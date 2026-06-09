找可以到石头i的所有k值，如果最后一块石头有k值，则说明青蛙能过河。 找石头i的所有k值时，要注意遍历i前面的所有石头。

    int dp[1100+10][1100] = { {0} };
    int *dpPre = NULL;
    int i = 0;
    int j = 0;
    int iK = 0;
    int jK = 0;
    int k = 0;
    int preK = 0;

    memset(dp, -1, sizeof(dp));

    if (stonesSize == 2) {
        return (stones[0] + 1 == stones[1]) ? true : false;
    }
    
    dp[1][0] = (stones[0] + 1 == stones[1]) ? 1 : -1;
    if (dp[1][0] == -1) {
        return false;
    }
    
    for(i = 2; i < stonesSize; i++) {
        iK = 0; /* 记录下标i的stone有多个k值的下标 */
        for(j = i - 1; j > 0; j--) {   /* 去找i前面的可以跳到i的所有k值，并记录在dp[i][k]中 */
            k = stones[i] - stones[j];  /* i到其某个前石头的k值 */
            dpPre = dp[j];
            for(jK = 0; jK < stonesSize;  jK++) {
                preK = dpPre[jK];
                if (preK == -1) { /* 走该分支，表明j 到 i没有路径 */
                    break;
                }
                
                if ((k == preK || k == preK - 1 || k == preK + 1)) {  /* 表明此石头可以通过k到i石头 */
                    dp[i][iK++] = k;
                    break; /* j石头到 i石头只有一个k值 */
                }
            }
        }
        /* 到i没有任何有效的k值, 仍然要继续往后面找，可能后面的石头可以找到更前面的石头 */
    }
    
    if (dp[--i][0] != -1) {
        return true;
    }
    return false;