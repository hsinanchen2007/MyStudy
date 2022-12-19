### 解题思路
此处撰写解题思路

### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    int i,j;
    i=0;
    j=1;
    while(j<numsSize){
        if(nums[j]!=nums[i]){
            i++;
            nums[i]=nums[j];
        }
        j++;
    }
    if (numsSize==0)
        return 0;
    return i+1;
}
```
好坑啊 还要考虑空数组