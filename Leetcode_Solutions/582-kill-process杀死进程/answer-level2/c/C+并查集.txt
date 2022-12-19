### 解题思路
C+并查集

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static int* S;

int find(int x, int kill) {
    if (x == 0) {
        return 0;
    }
    if (x == kill) {
        return kill;
    }
    else {
        x = find(S[x], kill);
    }
    return x;
}

int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize){
    int max = INT_MIN;
    for (int i = 0; i < pidSize; i++) {
        max = fmax(max, pid[i]);
    }
    S = (int*)malloc((max + 1)*sizeof(int));
    memset(S, 0, (max + 1)*sizeof(int));
    for (int i = 0; i < pidSize; i++) {
        int pidNum = pid[i];
        int ppidNum = ppid[i];
        S[pidNum] = ppidNum;
    }
    int* res = (int*)malloc(pidSize*sizeof(int));
    int resLen = 0;
    for (int i = 0; i < max+1; i++) {
        if (find(i, kill) == kill) {
            res[resLen] = i;
            resLen++;
        }
    }
    *returnSize = resLen;
    return res;
}
```