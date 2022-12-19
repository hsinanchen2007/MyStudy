```
int str_to_minute(char *str)
{
    return ((str[0] - '0')*10 + str[1] - '0')*60 + (str[3] - '0')*10 + str[4] - '0';
}

int findMinDifference(char ** timePoints, int timePointsSize){
    int *minute  = NULL;
    int min = INT_MAX;

    minute = malloc(sizeof(int)*timePointsSize);
    memset(minute, 0, sizeof(int)*timePointsSize);
    for(int i = 0; i < timePointsSize; i++)
    {
       minute[i] =  str_to_minute(timePoints[i]);
    }
    for(int i = 0; i < timePointsSize; i++)
    {
        for(int j = 0; j < timePointsSize; j++)
        {
            int tmp = 0;
            if(i >= j)
            {
                continue;
            }
            tmp = abs(minute[i] - minute[j]);
            if(tmp > 12 * 60)
            tmp = 24*60 - tmp;
            if(min > tmp)
            {
                min = tmp;
            }
        }
    }

    return min;
}
```
