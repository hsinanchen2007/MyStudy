int minSubArrayLen(int s, int *nums, int numsSize)
{
    int i = 0;
    int j = 0;
    if (numsSize == 0 || nums == NULL) {
        return 0;
    }
    int iMaxSize = 0x7FFFFFFF;
    int iSum = 0;
	int iLength;
	
    for (; (i < numsSize) || (j < numsSize);) {
        if ((s > iSum)) {
		    if ((j==numsSize)&&(i<numsSize))
			{
				break;
			}
            iSum += nums[j];
            j++;
        } else {
            iLength = j - i;
            if (iLength < iMaxSize) {
                iMaxSize = iLength;
            }
            iSum -= nums[i];
            i++;
        }
    }
    if (iMaxSize == 0x7FFFFFFF) {
        iMaxSize = 0;
    }
    return iMaxSize;
}