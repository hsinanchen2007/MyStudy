    double findMaxAverage(int* nums, int numsSize, int k){
    int i = 0;
    double retVal, eachSum = 0, maxVal;

    while(i < k && i < numsSize)
    {
    eachSum += nums[i];
    i++;
    }
    maxVal = eachSum;
    for(i = 1; i <= (numsSize - k); i++)
    {
    eachSum = eachSum - nums[i-1] + nums[i+k-1];
    if(eachSum > maxVal)
    {
    maxVal = eachSum;
    }
    }
    retVal = maxVal / k;
    return retVal;
    }