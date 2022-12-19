### 解题思路
从小到大顺序遍历，如果恰好相等就返回索引值
然后考虑数组中没有target的情况
1. 如果target大于所有的数组值，直接返回数组的大小，也就相当于数组最后一位+1
2. 如果target在两个数之间，遇到的第一个比target大的数的位置就是target插入的位置，这种情况可以和恰好相等放在一起

### 代码

```c
int searchInsert(int* nums, int numsSize, int target){
    for(int i=0;i<numsSize;i++) {
        if(nums[i]>=target){
            return i;
        }
    }
    return numsSize;
}
```