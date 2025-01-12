#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to read data from file
void read_data(const char *filename, int **data, int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    *size = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ',') {
            (*size)++;
        }
    }
    (*size)++;  // Account for the last number
    fseek(file, 0, SEEK_SET);  // Reset file pointer to beginning

    *data = (int *)malloc(*size * sizeof(int));
    if (*data == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < *size; i++) {
        fscanf(file, "%d,", &(*data)[i]);
    }
    fclose(file);
}

// Function to calculate mean
double calculate_mean(int *data, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

int main() {
    // Start timing the execution
    clock_t start_time = clock();

    int *data;
    int size;

    // Read data from the file
        read_data("C:/Users/akrit/Downloads/Test_sample_input_data_03.txt", &data, &size);
    printf("Number of samples in the data: %d\n", size);

    // Calculate threshold (mean of the dataset)
    double threshold = calculate_mean(data, size);
    printf("Threshold: %.2f\n", threshold);
    int cycles = 0;
    int total_samples_in_cycles = 0;  // To accumulate the total number of samples in all cycles
    int upper_peak = -1, lower_peak = -1;
    int in_cycle = 0;  // Flag to indicate we are inside a cycle
    int samples_in_current_cycle = 0;  // Counter for samples in the current cycle

    printf("Detected Cycles:\n");

    for (int i = 0; i < size; i++) {
        // Track upper peak (above threshold)
        if (data[i] > threshold) {
            if (upper_peak == -1 || data[i] > upper_peak) {
                upper_peak = data[i];
            }
        }

        // Track lower peak (below threshold)
        if (data[i] < threshold) {
            if (lower_peak == -1 || data[i] < lower_peak) {
                lower_peak = data[i];
            }
        }

        // Detect the end of a valid cycle
        if (data[i] > threshold && (i == 0 || data[i - 1] <= threshold)) {
            if (in_cycle) {
                // Only count the cycle if both upper and lower peaks are valid
                if (upper_peak != -1 && lower_peak != -1) {
                    printf("Cycle %d: Upper Peak = %d, Lower Peak = %d\n", ++cycles, upper_peak, lower_peak);
                    total_samples_in_cycles += samples_in_current_cycle;  // Add the samples to total
                }
                // Reset peaks for the next potential cycle
                upper_peak = -1;
                lower_peak = -1;
                samples_in_current_cycle = 0;  // Reset the sample counter for the next cycle
            }
            in_cycle = 1;  // Mark entering a new cycle
        }

        // If we are in a cycle, count the samples
        if (in_cycle) {
            samples_in_current_cycle++;
        }
    }
printf("Total detected cycles %d\n",cycles);
    // Calculate and print the average number of samples per cycle
    if (cycles > 0) {
        double avg_samples_per_cycle = (double)total_samples_in_cycles / cycles;
        printf("Average number of samples per cycle: %.2f\n", avg_samples_per_cycle);

        // Calculate and print the sampling rate
        double given_frequency = 60.0;
        double sampling_rate = given_frequency * avg_samples_per_cycle;  // 60 Hz * average number of samples per cycle
        printf("Sampling Rate: %.2f  samples/seconds \n", sampling_rate);
    } else {
        printf("No cycles detected.\n");
    }

    // Free allocated memory
    free(data);

    // End timing and calculate the elapsed time
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;  // Calculate time in seconds

    printf("Time taken to execute the program: %.4f seconds\n", time_taken);

    return 0;
}
