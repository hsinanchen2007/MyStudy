### 解题思路
写一个递归算法的思路，输入数据较少时结果正常，但是数据多了会超时。记下问题的拆分方法，便于加深自己对递归的理解和记忆。

##### 问题可以分成两种情况
1. 使用数组第一个元素，不用第二个
2. 使用数组第二个元素，不用第一个
##### 计算和边界处理
- 对于第一种情况，计算结果应该是**nums[0] + massage(&nums[2], numsSize - 2)**，因为使用了第一个元素就不能再用第二个，弃掉**nums[1]**
- 对于第二种情况，计算结果应该是**nums[1] + massage(&nums[3], numsSize - 3)**
- 然后返回两者中较大的一个
- 当numSize == 1时，直接返回nums[1]作为结果
- 当numSize <= 0时，返回0


### 代码

```c
// 递归算法超时
// int massage(int* nums, int numsSize){
//     if(numsSize == 1)
//         return nums[0];
//     else if(numsSize <= 0)
//         return 0;
//     else {
//         int r1 = nums[0] + massage(&nums[2], numsSize - 2);
//         int r2 = nums[1] + massage(&nums[3], numsSize - 3);
//         return r1 > r2 ? r1 : r2;
//     }
//     return -1;
// }

// 动态规划
int massage(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int r1 = 0;
    int r2 = nums[0];
    for(int i = 1; i <numsSize; i++) {
        int temp = r1;
        r1 = r1 > r2 ? r1 : r2;
        r2 = temp + nums[i];
    }
    return r1 > r2 ? r1 : r2;
}
```