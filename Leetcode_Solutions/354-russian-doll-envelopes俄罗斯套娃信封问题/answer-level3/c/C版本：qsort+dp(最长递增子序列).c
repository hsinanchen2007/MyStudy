```
#define MAX(a,b) ((a) > (b) ? (a):(b))

int compare(const void *p1, const void *p2){
    //宽度相同，按高度递减排
    if ((*(int**)p1)[0] == (*(int**)p2)[0]){
        return (*(int**)p2)[1] - (*(int**)p1)[1];
    }
    
    //宽度不同，按宽度递增排
    return (*(int**)p1)[0] - (*(int**)p2)[0];
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    int *dp;
    int max = 0;
    int i,j;

    if (envelopes == NULL || envelopesSize == 0) {
        return 0;
    }

    qsort(envelopes,envelopesSize,sizeof(int**),compare);
    
    dp = malloc(envelopesSize*sizeof(int));
    
    //下面就是基于宽度的最长递增子序列的问题了
    for (i=0;i<envelopesSize;i++) {
        dp[i] = 1; //子序列至少包括自己
        for (j = 0; j < i; j++) {
            if (envelopes[i][1] > envelopes[j][1]) {
                dp[i] = MAX(dp[i],dp[j]+1);
            }
        }

        max = MAX(max,dp[i]);
    }

    free(dp);
    return max;
}
```
