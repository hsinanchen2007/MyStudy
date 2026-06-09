![image.png](https://pic.leetcode-cn.com/b3efcc01a8ccc81e3406e5f03c1cc3e90c83a10336299c1a6b6f3ee6efe9c3ad-image.png)

```
#define LEN 16
#define MAX 26
#define MAX_NUM 450

struct strInfo {
    int len;
    char flag[MAX + 1];
};

struct strInfo g_strInfo[LEN];

int Cmp(const void *a, const void *b)
{
    return ((struct strInfo *)b)->len - ((struct strInfo *)a)->len;
}

/*字符串内部是否存在相同字符*/
int ExistInnerComm(char *a, int aSize)
{
    int queue[MAX] = {0};
    int temp;

    for (int i = 0; i < aSize; i++) {
        temp = a[i] - 'a';
        if (queue[temp]) {
            return 1;
        }
        queue[temp] = 1;
    }

    return 0;
}

/*两个字符串是否存在相同字符*/
int ExistComm(char *a, int aSize, char *b, int bSize)
{
    for (int i = 0; i < aSize; i++) {
        for (int j = 0; j < bSize; j++) {
            if (a[i] == b[j]) {
                return 1;
            }
        }
    }

    return 0;
}

int GetMax(int *a, int aSize)
{
    int max = 0;

    for (int i = 0; i < aSize; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }

    return max;
}

int maxLength(char ** arr, int arrSize){
    int len;
    int count[LEN] = {0}; //包含第i个字符串的最大长度
    int size;
    char flag[MAX_NUM]; //存储合并的字符串

    memset(g_strInfo, 0, LEN * sizeof(struct strInfo));

    for (int i = 0; i < arrSize; i++) {
        len = strlen(arr[i]);
        for (int j = 0; j < len; j++) {
            g_strInfo[i].flag[g_strInfo[i].len++] = arr[i][j];
        }
        g_strInfo[i].flag[g_strInfo[i].len] = '\0';
    }

    //按长度降序排序，目的是子字符串存在相同字符时，选择长度最长的合并
    qsort(g_strInfo, arrSize, sizeof(struct strInfo), Cmp); 

    for (int i = 0; i < arrSize; i++) {
        if (ExistInnerComm(g_strInfo[i].flag, g_strInfo[i].len)) {
            continue;
        }
        size = g_strInfo[i].len;
        strcpy(flag, g_strInfo[i].flag);
        count[i] = g_strInfo[i].len;
        for (int j = 0; j < arrSize; j++) {
            if (i != j && !ExistComm(flag, size, g_strInfo[j].flag, g_strInfo[j].len) &&
            !ExistInnerComm(g_strInfo[j].flag, g_strInfo[j].len)) {
                count[i] += g_strInfo[j].len;
                strcpy(flag + size, g_strInfo[j].flag);
                size += g_strInfo[j].len;
            }
        }
    }

    return GetMax(count, LEN);
}
```

**DFS**
![image.png](https://pic.leetcode-cn.com/c5adc1e487ae9f5e79e427baf94fcfa4dfba02d64cd71f14d6849cba84ccab3f-image.png)

DFS递归稍慢，DFS和BFS属于暴力算法，不到万不得已不要使用
```
#define MAX 26

int g_max;

int GetMax(int a, int b)
{
    return a > b ? a : b;
}

int ExistComm(char *a, int size, int *flag)
{
    int temp;

    for (int i = 0; i < size; i++) {
        temp = a[i] - 'a';
        if (flag[temp]) {
            return 1;
        }
        flag[temp] = 1;
    }

    return 0;
}

int DFS(char ** arr, int arrSize, int len, int curIdx, int *record)
{
    g_max = GetMax(g_max, len);

    for (int i = curIdx; i < arrSize; i++) {
        int flag[MAX] = {0};
        /*record用于记录子串字符统计*/
        if (record != NULL) {
            memcpy(flag, record, MAX * sizeof(int));
        }
        if (ExistComm(arr[i], strlen(arr[i]), flag)) {
            continue;
        }
        g_max = GetMax(g_max, DFS(arr, arrSize, len + strlen(arr[i]), i + 1, flag));
    }

    return g_max;
}

int maxLength(char ** arr, int arrSize){
    g_max = 0;
    return DFS(arr, arrSize, 0, 0, NULL);
}
```
