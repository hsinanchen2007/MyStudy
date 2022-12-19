### 解题思路
strcmp is all

### 代码

```c
typedef struct {
    int id;
    char buf[32];
    bool used;
} LogSystem;

#define MAX 310
LogSystem g_log[MAX];
int g_cnt[MAX];

LogSystem* logSystemCreate() {
    memset(g_log, 0, sizeof(g_log));
    memset(g_cnt, 0, sizeof(g_cnt));
    return NULL;
}

int GetPos(char *key)
{
    if (!strcmp(key, "Year")) {
        return 4;
    }    
    if (!strcmp(key, "Month")) {
        return 7;
    }
    if (!strcmp(key, "Day")) {
        return 10;
    }
    if (!strcmp(key, "Hour")) {
        return 13;
    }
    if (!strcmp(key, "Minute")) {
        return 16;
    }
    if (!strcmp(key, "Second")) {
        return 19;
    }
    return 0;
}

void logSystemPut(LogSystem* obj, int id, char * timestamp) {
    for (int i = 0; i < MAX; i++) {
        if (g_log[i].used) {
            continue;
        }
        g_log[i].used = true;
        g_log[i].id = id;
        strcpy(g_log[i].buf, timestamp);
        return;
    }
}

int* logSystemRetrieve(LogSystem* obj, char * s, char * e, char * gra, int* retSize) {
    * retSize = 0;
    int cnt = 0;

    int pos = GetPos(gra);
    printf("pos %d-%s\n", pos, gra);
    for (int i = 0; i < MAX; i++) {
        if (!g_log[i].used) {
            break;
        }
        char *key = g_log[i].buf;
        if (strncmp(s, key, pos) <= 0 && strncmp(key, e, pos) <= 0) {
            g_cnt[cnt++] = g_log[i].id;
            printf("g_log[i].id %d-%s\n", g_log[i].id, gra);
        }
    }

    int *out = NULL;
    if (cnt > 0) {
        * retSize = cnt;
        out = (int *)malloc(sizeof(int) * cnt);
        for (int i = 0; i < cnt; i++) {
            printf("%d-", g_cnt[i]);
            out[i] = g_cnt[i];
        }
        printf("\n");
        //memcpy(out, g_cnt, cnt);
    }
    return out;
}

void logSystemFree(LogSystem* obj) {
    printf("logSystemFree\n");
    memset(g_log, 0, sizeof(g_log));
}

/**
 * Your LogSystem struct will be instantiated and called as such:
 * LogSystem* obj = logSystemCreate();
 * logSystemPut(obj, id, timestamp);
 
 * int* param_2 = logSystemRetrieve(obj, s, e, gra, retSize);
 
 * logSystemFree(obj);
*/
```