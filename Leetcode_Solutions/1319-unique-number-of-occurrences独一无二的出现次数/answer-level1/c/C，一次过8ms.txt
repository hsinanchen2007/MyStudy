先统计每个数出现的次数，按照次数从大到小排序，除0以外验证有没有相同的数即可
int inc (const void * a,const void *b)
{
    return *(int *)b - *(int *)a;
}

bool uniqueOccurrences(int* arr, int arrSize){
    int times[2001] = {0};
    for(int i = 0;i < arrSize; i++)
    {
        int temp = arr[i] + 1000;
        times[temp]++;
    }
    qsort(times, 2001, sizeof(int), inc);
    for(int i = 0;i < 2000; i++)
    {
        if(times[i] == times[i+1])
        {
            return false;
        }
        if(times[i+1] == 0)
        {
            break; 
        }
    }
    return true;
}