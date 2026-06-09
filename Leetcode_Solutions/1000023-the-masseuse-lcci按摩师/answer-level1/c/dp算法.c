### 解题思路
此处撰写解题思路
要理解dp的思想，i 的问题基于 i-1 的问题
### 代码

```c
int massage(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    
    int dp0 = 0;
    int dp1 = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int tdp0 = dp0 > dp1 ? dp0 : dp1;
        int tdp1 = dp0 + nums[i];

        dp0 = tdp0;
        dp1 = tdp1;
    }

    return dp0 > dp1 ? dp0 : dp1;
}
```