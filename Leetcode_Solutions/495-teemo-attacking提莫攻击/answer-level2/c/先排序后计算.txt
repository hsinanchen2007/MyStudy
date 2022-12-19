### 解题思路
此处撰写解题思路

先排序后计算

### 代码

```c
int MyCompare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration)
{
    if (!timeSeries || timeSeriesSize < 1 || duration < 1) {
        return 0;
    }

    qsort(timeSeries, timeSeriesSize, sizeof(int), MyCompare);
    int sum = 0;
    for (int i = 0; i < timeSeriesSize - 1; i++) {
        if ((timeSeries[i] + duration) < timeSeries[i + 1]) {
            sum += duration;
        }
        else {
            sum += timeSeries[i + 1] - timeSeries[i];
        }
    }

    return sum + duration;
}
```