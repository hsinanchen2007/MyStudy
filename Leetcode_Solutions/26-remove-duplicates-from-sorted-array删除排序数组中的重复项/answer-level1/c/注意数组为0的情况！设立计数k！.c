### 解题思路
它的要求其实只是返回不重复数字的个数。并且不要求你另外再建立一个数组！！
那么就是说明你需要把不重复的数字按照顺序排序呗！
本来就是排好序的数组，那么你只需将每个不相同的数给你建立的k！！你从第二个开始对比，只需要跟k比就行！！
注意：最后输出的是个数，那么就是k+1。
（并不知道自己有没有表达清楚？）
### 代码

```c
int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0) return 0;
    int k=0;
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=nums[k]){
            k++;
            nums[k]=nums[i];
        }
    }
    return k+1;
}
```