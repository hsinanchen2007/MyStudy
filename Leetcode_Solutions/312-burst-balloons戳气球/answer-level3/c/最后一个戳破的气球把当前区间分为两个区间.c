### 解题思路
此处撰写解题思路

### 代码

```c

int maxCoins(int* nums, int numsSize){
    int ret = 0;
    int res = 0;
    int buf[502] = {0};
    int dp[502][502] = {0};
    int max = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    
    if (0 == numsSize)
    {
        return 0;
    }
    
    buf[0] = 1;
    memcpy(buf+1, nums, numsSize*sizeof(int));
    buf[numsSize+1] = 1;
    
    for (i = numsSize-1; i >= 0; i--) 
    {
        for (j = i + 2; j < numsSize+2; j++) 
        {
            max = 0;
            for (k = i + 1; k < j; k++) 
            {
                res = dp[i][k] + dp[k][j] + buf[i] * buf[k] * buf[j];
                if (res > max) 
                {
                    max = res;
                }
            }
            dp[i][j] = max;
        }
    }

    return dp[0][numsSize+1];
}
```