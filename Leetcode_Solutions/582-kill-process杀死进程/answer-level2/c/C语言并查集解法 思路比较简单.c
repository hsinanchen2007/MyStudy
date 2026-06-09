注意一下找祖先的时候，不是找根祖先，找到要被杀死的进程就停，其他和普通并查集一样
```
#define MAX_SIZE 1000000
int g_father[MAX_SIZE] = {0};
int g_kill = 0;
int FindFather(int x) {
    while (g_father[x] != x) {
        if (x == g_kill) {
            g_father[x] = x;
            return x;
        } else {
            x = g_father[x];
        }
    }
    return x;
}
int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize){
    for (int i = 0; i < MAX_SIZE; i++) {
        g_father[i] = i;
    }
    g_kill = kill;
    for (int i = 0; i < ppidSize; i++) {
        if (FindFather(pid[i]) != FindFather(ppid[i])) {
            g_father[FindFather(pid[i])] = FindFather(ppid[i]);
        }
    }
    int *result = (int*)malloc(MAX_SIZE * sizeof(int));
    int k = 0;
    for (int i = 0; i < ppidSize; i++) {
        if (FindFather(pid[i]) == kill) {
            result[k++] = pid[i];
        }
    }
    *returnSize = k;
    return result;
}
```
