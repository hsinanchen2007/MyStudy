### 解题思路
1、递归算法
2、[0, Sn],[0, Tn]的个数等于，[1, Sn],[0, Tn] (S0 == T0 || S0 != T0的时候) + [1, Sn],[1, Tn] （S0 == T0的时候）的个数；
3、递归太耗时，会超时，需要加记忆。记录每次走过的节点之后的个数，后面再走的时候，直接获取记忆的值，减少递归的层次。

### 代码

```c


int **map = NULL;

int getCount(char* s, int sStrat, char* t, int tStart)
{
    int count = 0;

    if (tStart == strlen(t)) {
        return 1;
    }
    if (sStrat == strlen(s)) {
        return 0;
    }

    if (map[sStrat][tStart] != -1) {
        return map[sStrat][tStart];
    }
    if (*(s + sStrat) == *(t + tStart)) {
        count += getCount(s, sStrat + 1, t, tStart + 1);
    }

    count += getCount(s, sStrat + 1, t, tStart);

    map[sStrat][tStart] = count;
    return count;
}

int numDistinct(char * s, char * t){
    int count = 0;
    int sLen = strlen(s) + 1;
    int tLen = strlen(t) + 1;
    int i = 0;

    map = (int **)malloc(sLen * sizeof(int *));
    for (i = 0; i < sLen; i++) {
        map[i] = (int *)malloc(tLen * sizeof(int));
        memset(map[i], -1, tLen * sizeof(int));
    }
     
    if (s == NULL) {
        return 0;
    }
    count = getCount(s, 0, t, 0);

    for (i = 0; i < sLen; i++) {
        free(map[i]);
    }
    free(map);

    return count;
}
```