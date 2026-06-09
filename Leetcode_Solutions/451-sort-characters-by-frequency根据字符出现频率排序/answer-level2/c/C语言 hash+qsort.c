### 解题思路

![image.png](https://pic.leetcode-cn.com/32adbe8f005dbff09edd508dc7b40d7fbaa2901dd6441969e61283e11cc5cfe1-image.png)

### 代码

```c
#define MY_TABLE_SIZE 128
typedef struct {
    char ch;
    int cnt;
} MyCh;

void cInit(MyCh chs[MY_TABLE_SIZE])
{
    int i;
    for (i = 0; i < MY_TABLE_SIZE; i++) {
        chs[i].ch = (char)i;
        chs[i].cnt = 0;
    }
    return;
}

int cmp(const void *a, const void *b)
{
    return ((MyCh*)a)->cnt < ((MyCh*)b)->cnt;
}

void proc(MyCh chs[MY_TABLE_SIZE], char *s)
{
    while(*s != '\0') {
        chs[*s].cnt++;
        s++;
    }
    qsort(chs, MY_TABLE_SIZE, sizeof(MyCh), cmp);
}

char* rlt(MyCh chs[MY_TABLE_SIZE], char *s)
{
    int i, j;
    int inx = 0;
    char *rlt = NULL;
    rlt = (char*)calloc(strlen(s) + 1, sizeof(char));
    if (rlt == NULL) {
        return NULL;
    }
    for (i = 0; i < MY_TABLE_SIZE; i++) {
        if (chs[i].cnt == 0) {
            continue;
        }
        for (j = 0; j < chs[i].cnt; j++) {
            rlt[inx++] = chs[i].ch;
        }
    }
    return rlt;
}
char * frequencySort(char * s){
    MyCh chs[MY_TABLE_SIZE] = { 0 };
    if (*s == '\0') {
        return "";
    }
    cInit(chs);
    proc(chs, s);
    return rlt(chs, s);
}
```