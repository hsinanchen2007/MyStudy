/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    int ret = 0, i = 0, tmp = 0, nums_1 = 0, nums_2 = 0;
    *returnSize = 2;
    int *arr = (int*)malloc(sizeof(int) * *returnSize);
    while (i<numsSize)
    {
        ret ^= *(nums + i);             //ret == 两个只出现一次的数 异或的值
        ++i;
    }
    for(int i = 0; i < 32; ++i)
    {
       if(((ret >> i) & 1)  == 1)
       {
           tmp = i;                       //求出ret 二进制中第一个1的位置，记为 tmp
           break;
       }
    }
    for(int i = 0; i < numsSize; ++i)
    {
        if(((nums[i] >> tmp) &1) == 1)    //分为2组，一组为tmp 处为1 的
            nums_1 ^= nums[i];
        else
            nums_2 ^= nums[i];             //tmp处不为1的
    }
    arr[0] = nums_1;
    arr[1] = nums_2;
    return arr;

}