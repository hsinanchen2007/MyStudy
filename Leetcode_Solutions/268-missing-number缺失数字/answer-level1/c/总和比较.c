### 解题思路
既然数组中少了一个值，那么也就是说数组的总和与1+2+3+......+n的总和之差就是这个值。

### 代码

```c
int missingNumber(int* nums, int numsSize){
    int totaln = (1+numsSize)*numsSize/2,total = 0;
    for(auto i = 0;i < numsSize;i++){
        total += nums[i];
    }
    return totaln-total;
}
```