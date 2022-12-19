滑窗求解
```

int numOfSubarrays(int* arr, int arrSize, int k, int threshold){
    if (arr == NULL || arrSize <= 0 || k <= 0 || k > arrSize) {
        return 0;
    }
    int thresholdK = k * threshold;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    if (sum >= thresholdK) {
        count++;
    }
    for (int i = k; i < arrSize; i++) {
        sum += (arr[i] - arr[i - k]);
        if (sum >= thresholdK) {
            count++;
        }
    }
    return count;
}
```
