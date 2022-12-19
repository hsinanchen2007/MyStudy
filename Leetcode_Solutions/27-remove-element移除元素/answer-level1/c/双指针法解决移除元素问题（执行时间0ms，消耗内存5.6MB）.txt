### 解题思路
使用双指针法，i为慢指针，j为快指针。其中i指针用来标记下一个非重复元素可以移动到的位置，j指针用来快速遍历数组，当nums[j]不等于val的时候就将该元素往前移到指针i所在的位置。

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int i,j;
    i=0;
    for (j=0;j<numsSize;j++)
    {
        if(nums[j]!=val)
        {
            nums[i]=nums[j];
            i++;
        }
    }
    return i;
}
```