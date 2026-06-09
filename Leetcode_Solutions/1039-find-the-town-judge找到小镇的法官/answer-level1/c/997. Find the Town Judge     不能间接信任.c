### 解题思路
１．　弄清楚题意，　　　　不能间接信任，即每个人都必须直接信任法官
[1,2] [3,2] [2,4]  这是没有法官的。　不要被例５想复杂了

２．　巧用出度，dp[trust[i][0]]--;　　　法官如果信任了别就减一

### 代码

```c
int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int *dp = malloc((N + 1)* sizeof(int));
    int i = 0;

    memset(dp, 0 , (N + 1) * sizeof(int));
    for (i = 0; i < trustSize; i++) {
        dp[trust[i][0]]--;
        dp[trust[i][1]]++;
    }

    for (i = 1; i <= N; i++) {
        if (dp[i] == N -1)
            return i;
    }

    return -1;
}
```