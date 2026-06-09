### 解题思路
求和

### 代码

```c
int missingNumber(int* nums, int numsSize){
    int max = numsSize * (numsSize + 1) / 2;
    int i, num = 0;
    for (i = 0; i < numsSize; i++) num += nums[i];
    return max - num;
}
```