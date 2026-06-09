 int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int* sortArray(int* nums, int numsSize, int* returnSize)
{
    * returnSize = numsSize;
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    return nums;
}