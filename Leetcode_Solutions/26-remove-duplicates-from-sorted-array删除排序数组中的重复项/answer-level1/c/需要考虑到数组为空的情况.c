### 解题思路
因为是有序的数组，所以数组里元素的值是递增或者等于前一个元素的值
因为要移除数组里重复项，所以只有后一个元素值大于前一个元素值才能被留下
使用两个下标i,j，i用来遍历数组，不断指向下一个元素；j用来确定互不相同的数组的最后一个元素
最后结果为j+1
ps：需要考虑到数组为空的情况。

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if (numsSize == 0)
        return 0;
    
    int i,j=0;
    for ( i = 1; i < numsSize; i++)
        if (nums[i] != nums[j])
            nums[++j] = nums[i];

     return j+1;
}
```