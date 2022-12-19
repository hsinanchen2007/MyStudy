### 解题思路
此处撰写解题思路

### 代码

```c
# define MAX(a,b) ((a) > (b)) ? (a) : (b)

int lengthOfLIS(int* nums, int numsSize){
    if(numsSize <= 0) {
        return 0;
    }
    int* dp = (int*)malloc(sizeof(int)*numsSize);
    int max_ret = 0;

    for(int i = 0 ; i < numsSize ; i++){
        int max_v = 0;
        for( int j = 0 ; j < i; j++){
            if(nums[j] < nums[i]){
                max_v = MAX(max_v,dp[j]);
            }
        }
        dp[i] = max_v + 1;
        max_ret = MAX(max_ret,dp[i]);
    }
    return max_ret;
}

// 优化称O(nlogn)时间复杂度需要在升序dp数组中采用二分查找方式降低内部循环复杂度
```