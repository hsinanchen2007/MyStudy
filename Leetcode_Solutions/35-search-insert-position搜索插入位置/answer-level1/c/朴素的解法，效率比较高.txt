### 解题思路
虽然题目中分别给定了找到数字与找不到数字的处理办法，但其实他们可以用一种方法统一处理；
简单朴素又易懂，性能平淡无奇。

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    int i = 0;
    for(i;i < numsSize;i++){
        if(nums[i] >= target)
            break;
    }
    return i;
}
```