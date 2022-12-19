```
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration)
{
    int ans;
    int i, n;
    ans = 0;
    if (timeSeriesSize == 0) {
        return 0;
    }
    for (i = 0; i < timeSeriesSize - 1; i++) {
        n = timeSeries[i] + duration;
        if (timeSeries[i + 1] >= n) {
            ans = ans + duration;
        } else {
            ans = ans + duration - (n - timeSeries[i + 1]);
        }
    }
    ans = ans + duration;
    return ans;
}
```
