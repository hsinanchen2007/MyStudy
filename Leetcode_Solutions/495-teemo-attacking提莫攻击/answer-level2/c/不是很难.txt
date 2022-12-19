后一个元素和前面元素之差小于duration，则持续时间为后一个元素减前一个元素

```c
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    
    int result = 0;
    if(timeSeriesSize == 0)
        return 0;
    for (size_t i = 0; i < timeSeriesSize-1; i++)
    {
        if(timeSeries[i+1] - timeSeries[i] >= duration )
        {
            result += duration;
        }
        else
        {
            result += timeSeries[i+1] - timeSeries[i];
        }
    }
    return result + duration;
}
```

执行用时 : 52 ms, 在Teemo Attacking的C提交中击败了55.56% 的用户      

内存消耗 : 8.4 MB, 在Teemo Attacking的C提交中击败了72.73% 的用户