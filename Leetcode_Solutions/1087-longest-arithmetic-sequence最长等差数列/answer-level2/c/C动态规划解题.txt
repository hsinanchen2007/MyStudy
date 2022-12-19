### 解题思路
数组后一个元素和前一个元素的差值diff加上前一个元素在差值diff的最长等差数列长度即为当前元素在diff的最长等差数列长度

### 代码

```c
int longestArithSeqLength(int* A, int ASize){
    int * dp = NULL;
    int max = 2;
    int len = 0;
    int diff = 0;
    int idx1 = 0;
    int idx2 = 0;
    int i = 0;
    int j = 0;
    
    dp = (int *)malloc(ASize*20001*sizeof(int));
    
    for (i = 1; i < ASize; i++)
    {
        for (j = 0; j < i; j++)
        {
            diff = A[i]-A[j]+10000;
            idx1 = i*20001+diff;
            idx2 = j*20001+diff;
            
            if (0 == dp[idx1])
            {
                dp[idx1] = 2;
            }
            
            len = 1+dp[idx2];
            if (len > dp[idx1])
            {
                dp[idx1] = len;
                if (len > max)
                {
                    max = len;
                }
            }
        }
    }
    
    free(dp);
    
    return max;
}
```