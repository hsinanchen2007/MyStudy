并查集，需要修改下，在找到kill pid就停下来不找根节点。
```
int g_father[100000];
int g_kill = 0;
int findfather(int x)
{
    while(g_father[x] != x) {
        if (g_father[x] == g_kill) {
            x = g_father[x];
            return x;
        } else {
            x = g_father[x];
        }
    }
    return x;
}

int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize){
    int index;
    g_kill = kill;
    int num = 0;
    int *ret = malloc(100000*sizeof(int));
    for (index = 0; index < pidSize; index++) {
        g_father[pid[index]] = pid[index];
    }
    for (index = 0; index < pidSize; index++) {
        if (findfather(pid[index]) == g_kill) {
            continue;
        }
        if (findfather(pid[index]) != findfather(ppid[index])) {
            g_father[pid[index]] = g_father[ppid[index]];
        }
    }
    for (index = 0; index < pidSize; index++) {
        //printf("[%d]-%d\n",pid[index],findfather(pid[index]));
        if (findfather(pid[index]) == g_kill) {
            ret[num] = pid[index];
            num++;
        }
    }
    *returnSize = num;
    return ret;
}
```
