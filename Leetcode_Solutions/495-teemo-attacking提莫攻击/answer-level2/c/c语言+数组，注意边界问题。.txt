### 解题思路
![image.png](https://pic.leetcode-cn.com/207c1539782aeb20faa8ff87e137c1cdf6d8519de096e37fc97c2b7b5fed2cac-image.png)

### 代码

```c
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    if(NULL== timeSeries || 0 == timeSeriesSize)
    {
        return 0;
    }

    int totalTime = 0;

    for(int i = 0;i < timeSeriesSize - 1;i++)
    {
        
        if((timeSeries[i] + duration) < timeSeries[i + 1] )
        {
            totalTime += duration; 
        }
        else
        {
            totalTime += timeSeries[i+1] - timeSeries[i];
        }
    }

    return  totalTime + duration;
}
```