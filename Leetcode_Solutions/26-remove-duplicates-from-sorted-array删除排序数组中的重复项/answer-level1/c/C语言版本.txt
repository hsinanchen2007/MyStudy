### 解题思路
用一个指针cur指示非重复元素数组的长度。由于题干给出数组为“排序数组”，故可用nums[i]!=nums[i+1]来判断数组紧邻的两个元素是否相等。若出现不等，则将后者加入目的数组中，cur++。
最后注意判断numsSize是否为0。
### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int cur=1;
    for(int i=0;i<numsSize-1;i++)
        if(nums[i]!=nums[i+1])
            nums[cur++]=nums[i+1];
    return numsSize==0 ? 0 : cur;
}