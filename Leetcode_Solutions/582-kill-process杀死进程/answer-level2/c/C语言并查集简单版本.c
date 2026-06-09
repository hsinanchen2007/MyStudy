![image.png](https://pic.leetcode-cn.com/9500aae565e06456750f135ad02c5f9cc532746d7fc2f7c4e84137918caeef07-image.png)
```
#define MAX 100000
int g_father[MAX] = {0};
int dfs(int root, int kill, int *rst, int *returnSize)
{
    if (g_father[root] == kill) {
        return root;
    }
    if (g_father[root] == -1) return -1;
    if (dfs(g_father[root], kill, rst, returnSize) > 0) {
        return root;
    }else {
        return -1;
    }
}

int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize){
    for (int i = 0; i < MAX; i++) g_father[i] = -1;
    for (int i = 0; i < ppidSize; i++) {
        g_father[pid[i]] = ppid[i];
    }
    for (int i = 0; i < 15; i++) printf("%d ", g_father[i]);
    int *rst = (int *)calloc(pidSize+ppidSize, sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < pidSize; i++) {
        if (pid[i] == kill) {
            rst[*returnSize] = pid[i];
            (*returnSize)++;
        }
        if (dfs(pid[i], kill, rst, returnSize) != -1) {
            rst[*returnSize] = pid[i];
            (*returnSize)++;
        }
    }
    return rst;
}
```
