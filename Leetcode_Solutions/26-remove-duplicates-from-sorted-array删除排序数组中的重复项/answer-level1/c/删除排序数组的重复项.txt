### 前后元素进行对比
- 1.增加一个计数器k，初始化值为1，用于计算表中互不相同的元素个数。

- 2.遍历整个表，依次把后面元素与前面的进行对比：例如把表中nums[1]和基准值p(nums[0])对比，**如果两个元素相同**，只有i进行累加，此时k值不变，程序上可以不做处理。**如果两个结点值不相同**，按照新的位序排列表中元素nums[k]=nums[i]，计数器k+1。然后进行下一次的比较，最终返回新的表长，值为k，完成算法。
```c
int removeDuplicates(int *nums,int numsSize){
    if (numsSize == 0 || numsSize == 1) return numsSize;
    //k为计数器，计算新表里面不相同元素的个数
    int k = 1;
    for (int i = 1;i < numsSize; i++){
        if (nums[i] != nums[i-1]){
            nums[k++] = nums[i];
        }
    }
    return k;
}
```
点此下一题解：[删除排序数组中的重复项 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/solution/shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-xiang-i-3)