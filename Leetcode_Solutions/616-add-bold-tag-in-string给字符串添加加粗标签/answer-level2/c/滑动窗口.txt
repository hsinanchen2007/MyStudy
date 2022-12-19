### 解题思路
// 1. 先找pos对，加到数组里,考虑dst 在 src里有多份的场景
// 2. 排序，按pos对的begin排序后，使用 “滑动窗口” 归并pos对，得到有效pos对
// 3。拼接out，按pos对 拼接out，考虑头、尾

### 代码

```c
// 1. 先找pos对，加到数组里,考虑dst 在 src里有多份的场景
// 2. 排序，按pos对的begin排序后，使用 “滑动窗口” 归并pos对，得到有效pos对
// 3。拼接out，按pos对 拼接out，考虑头、尾
typedef struct {
    int beg;
    int end;
    bool valid;
} Point;

Point g_point[10000]; // 10000:max
int g_cnt;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int Com(const void *a, const void *b)
{
    Point a1 = *(Point *)a;
    Point b1 = *(Point *)b;
    return a1.beg > b1.beg;
}

char g_out[3000]; // 3000:max

void Find(char * s, char ** dict, int dictSize)
{
    int i;
    for(i = 0; i < dictSize; i++) {
        char *start = strstr(s, dict[i]);
        if (start == NULL) {
            continue;
        }        
        g_point[g_cnt].beg = start - s;
        g_point[g_cnt].end = start + strlen(dict[i]) - s;
        g_cnt++;
        start = strstr(start + 1, dict[i]);
        while (start != NULL) {
            g_point[g_cnt].beg = start - s;
            g_point[g_cnt].end = start + strlen(dict[i]) - s;
            g_cnt++;            
            start = strstr(start + 1, dict[i]);
        }
    }
}

void Sort()
{
    qsort(g_point, g_cnt, sizeof(Point), Com);
    int validCnt = 0;
    for (int i = 0; i < g_cnt - 1; i++) {
        if (g_point[i].end < g_point[i + 1].beg) {
            g_point[i].valid = true;
            validCnt++;
            continue;
        }
        // >=
        g_point[i + 1].beg = g_point[i].beg;
        g_point[i + 1].end = MAX(g_point[i].end, g_point[i + 1].end);        
    }
    g_point[g_cnt - 1].valid = true;
}

char * addBoldTag(char * s, char ** dict, int dictSize){
    memset(g_point, 0, sizeof(g_point));
    memset(g_out, 0, sizeof(g_out));
    g_cnt = 0;
    Find(s, dict, dictSize);

    if (g_cnt == 0) {
        return s;
    }
    Sort();

    int len = strlen(s);
    char *p = s;
    strncpy(g_out, s, g_point[0].beg - 0);
    p += g_point[0].beg;

    int last = 0;
    int i;
    for (i = 0; i < g_cnt; i++) {
        if (!g_point[i].valid) {
            continue;
        }
        int beg = g_point[i].beg;
        int end = g_point[i].end;
        last = end;

        char buf[20000];  // 20000:max
        memset(buf, 0, sizeof(buf));
        strcpy(buf, "<b>");
        strncat(buf, s + beg, end - beg);
        strcat(buf, "</b>");

        strncat(g_out, p, beg - (p - s));
        strcat(g_out, buf);
        p = s + end;
    }
    if (last < strlen(s)) {
        strcat(g_out, s + last);
    }
    return g_out;
}
```