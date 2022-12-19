//和题目26很相似，逐个遍历，判断数组中的数值，不同的时候存入新的数组中，数组下标为j，都遍历完j+1就是改变之后新数组中元素个数
int removeElement(int* nums, int numsSize, int val)
{
    int i,j=0;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]!=val)
        {
            nums[j]=nums[i];
            j++;
        }
    }
    return j;
}