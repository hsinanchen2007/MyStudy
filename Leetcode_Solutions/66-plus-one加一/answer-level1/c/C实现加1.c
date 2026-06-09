int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    if(digits == NULL || returnSize == NULL || digitsSize==0)
    return NULL;
    int c=0;  
    for(int i=digitsSize-1;i>=0;i--)
    {
        if(i == digitsSize-1)digits[i] = digits[i]+1;
        else digits[i] = digits[i]+c;
        c= digits[i]/10;
        digits[i]=digits[i]%10;
    }
    int *nums;
    if(c == 0)
    {
        nums = (int*)malloc(sizeof(int)*(digitsSize));
        memcpy(nums,digits,sizeof(int)*(digitsSize));
        *returnSize = digitsSize;
    }
    else
    {
        nums = (int*)malloc(sizeof(int)*(digitsSize+1));
        nums[0] = 1;
        memcpy(nums+1,digits,sizeof(int)*(digitsSize));
        *returnSize = digitsSize+1;
    }
    return nums;
}