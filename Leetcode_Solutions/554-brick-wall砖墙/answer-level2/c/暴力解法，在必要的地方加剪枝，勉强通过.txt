### 解题思路
1、先把各行，各个元素的和分别算出来；
2、从第0行开始，看各个元素和在后面行里是否包含相同数，如果有的话就+1；
3、找出最大的相同和数，就得到对应答案了。

注意：需要特别考虑每行都只有1个砖的情况；




### 代码

```c
/* 以空间换时间，貌似用全局变量比动态申请时间小 */
int sam[10000][10000] = {0};
long long sum[10000][10000] = {0};
int hash[10000][100] = {0}; /* 做了最简单的hash，帮助快速确认本行是否包含要查的值 */
int leastBricks(int** wall, int wallSize, int* wallColSize){
    int i;
    int j;
    int maxsame = 0;
    int k;
    int l;
    int flag = 0;
    if ((wall == NULL) || (wallSize == 0) || (wallColSize == NULL)) {
        return 0;
    }
    for (i = 0; i < wallSize; i++) {
        if (wallColSize[i] != 1) {
            flag = 1;
        }
    }
    if (flag == 0) {
        return wallSize;
    }
    for (i = 0; i < wallSize; i++) {
    memset(sam[i],0,wallColSize[i] * 4);
    memset(hash[i],0,wallColSize[i] * 4);
    }
    for (i = 0; i < wallSize; i++) {
        sum[i][0] = (long long)wall[i][0];
        hash[i][sum[i][0] % 100] = 1;
        for (j = 1; j < wallColSize[i] - 1; j++) {
            sum[i][j] = sum[i][j - 1] + wall[i][j];
            hash[i][sum[i][j] % 100] = 1;
        }
    }
    for (i = 0; i < wallSize - maxsame -1; i++) { /* 找出最大值后，更新要查找的行数；每行只会往后找，如果前面已经找到N个相同数，后面N行就不用再找了 */
        for (j = 0; j < wallColSize[i] - 1; j++) {
            if (sum[i][j] == 0) { /* 已经查找过，就不用再找了 */
                continue;
            }
            for (k = i + 1; k < wallSize; k++) {
                if (hash[k][sum[i][j] % 100] == 0) {
                    continue;
                }
                for (l = 0; l < wallColSize[k] - 1; l++) {
                    if (sum[i][j] == sum[k][l]) {
                        sam[i][j]++;
                        sum[k][l] = 0; /* 标记成已经查找过 */
                    } 
                }
            }
            maxsame = ((sam[i][j] > maxsame) ? sam[i][j]: maxsame);
        }
            
    }
    return wallSize- maxsame -flag;
}
```