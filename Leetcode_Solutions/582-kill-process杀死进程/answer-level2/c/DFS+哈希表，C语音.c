父进程为0的记为1，为KILL的记为2

```
#define MAXNUM 100000
#define TRUEFLAG 2

bool Dfs(int cur, int* pid, int* ppid, int ppidSize, int kill, int *map)
{
    bool rslt = false;

    if (ppid[cur] == kill) {
        return true;
    }

    if (ppid[cur] == 0) {
        return false;
    }
    
    if (map[ppid[cur]] == 1) {
        return false;
    }

    if (map[ppid[cur]] == TRUEFLAG) {
        return true;
    }

    for (int i = 0; i < ppidSize; i++) {
        if (pid[i] == ppid[cur]) {
            rslt = Dfs(i, pid, ppid, ppidSize, kill, map);

            if (rslt == false) {
                map[ppid[cur]] = 1;
            } else {
                map[ppid[cur]] = TRUEFLAG;
            }
            break;
        }
    }
    
    return rslt;
}

int* TerminateProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize)
{
    int i;
    int tem;
    bool flag = false;
    int m = 0;
    int *r = NULL;
    int map[MAXNUM] = {0};
    

    r = (int *)malloc(sizeof(int) * MAXNUM);
    for (i = 0; i < pidSize; i++) {
        tem = pid[i];
        if (tem == kill) {
            r[m++] = tem;
            continue;
        }

        if (map[tem] == 1) {
            continue;
        }

        if (map[tem] == TRUEFLAG) {
            r[m++] = tem;
            continue;
        }

        flag = Dfs(i, pid, ppid, ppidSize, kill, map);
        if (flag == true) {
            r[m++] = tem;
            map[tem] = TRUEFLAG;
        } else {
            map[tem] = 1;
        }
    }

    *returnSize = m;
    return r;
}
```
