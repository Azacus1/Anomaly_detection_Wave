# Anomaly_detection_Wave
Anomaly detection in electric waves identifies irregular patterns or deviations from normal waveforms in electrical signals. It leverages machine learning or statistical methods to detect faults, power quality issues, or equipment malfunctions in real-time, ensuring system reliability.


# Cycle Detection and Sample Analysis Program

## Problem Statement
The task is to analyze sample data provided in files and perform the following tasks:
1. *Initialize Inputs:* Read sample data from files and store it in an array.
2. *Cycle Detection:* Identify the number of cycles in the data.
3. *Sample Counting:* Calculate the average number of samples in each cycle.
4. *Cycle Analysis:* Identify maximum and minimum values (upper and lower peaks) within each cycle.
5. *Optimization:* Focus on time complexity, space usage, and quick output.

---

## Algorithmic Approach
### Step 1: Initialize Variables
- Declare variables to store sample data, cycle counts, peaks, and other metrics.
- Initialize flags and counters for tracking cycles and samples.

### Step 2: Read Data from File
- Open the input file and read its contents into an array.
- Determine the size of the data and store the integers in memory.

### Step 3: Calculate Threshold
- Compute the threshold as the mean of the sample data values.

### Step 4: Cycle Detection
- Iterate through the data array to:
  - Detect cycles based on transitions above and below the threshold.
  - Track upper and lower peaks within each cycle.

### Step 5: Metrics Calculation
- Calculate:
  - Average number of samples per cycle.
  - Sampling rate in samples/second.

### Step 6: Output Results
- Print details including:
  - Number of samples, threshold, detected cycles, average samples per cycle, and sampling rate.

### Step 7: Performance Analysis
- *Time Complexity:* \( O(n) \)
- *Space Complexity:* \( O(1) \)

---

## Code Overview
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes and main algorithm implementation****
