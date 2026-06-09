### 解题思路
循环遍历数组，记录确实数字的个数，与K比较，大于等于即可求出缺失的数字，遍历结束仍未找到第K个，就在数组最后一个元素基础上继续寻找，返回第K个缺失数字
### 代码
c
int missingElement(int* nums, int numsSize, int k){
    int i;
    int cnt = 0;
    
    for(i = 1; i < numsSize; i++) {
        cnt += nums[i] - nums[i - 1] - 1;
        
        if(cnt >= k) {
            return nums[i] - 1 - (cnt - k);
        }
    }
    
    return nums[i - 1] + k - cnt;
}
```