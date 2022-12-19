
int minSubArrayLen(int s, int* nums, int numsSize){
    int sum = 0;
    int begin = 0;
    int minLen = numsSize;
    int finded = 0;

    for (size_t i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        while ( sum >= s )
        {
            int tempLen = i - begin + 1;
            minLen = minLen < tempLen ? minLen : tempLen;
            sum -= nums[begin];
            begin++;
            finded++;
        }
    }

    if (finded == 0)
    {
        minLen = 0;
    }
    

    return minLen;
}
