### 解题思路
解法一：用k记录数组nums中不等于val的元素个数，边扫描边统计k，并将不等于x的元素向前移动k个位置，最后修改数组长度
解法二：用k记录数组中等于val的元素个数。

### 代码

```c
int removeElement(int* nums, int numsSize, int val){
    int k=0;     //第一种解法
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=val)
            nums[k++]=nums[i];
    }
    return k;
    // int k=0;
    // for(int i=0;i<numsSize;i++){
    //     if(nums[i]==val)
    //         k++;
    //     else
    //         nums[i-k]=nums[i];
    // }
    // return numsSize-k;
}
```