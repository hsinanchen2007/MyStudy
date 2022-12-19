bool containsDuplicate(int* nums, int numsSize){
int i,j;
    if(numsSize==0||numsSize==1) return false;
    int comp(void *a,void *b)
    {
        return *(int*)a-*(int *)b;
    }
    qsort(nums,numsSize,sizeof(int),comp);
    for(i=0;i<numsSize-1;i++)
    {
        if(nums[i]==nums[i+1])  return true;}
    return false;
}