```c
// 线段覆盖问题， 贪心算法
#define MAX(a, b) ((a) > (b) ? (a): (b))
typedef struct {
    int begin;
    int end;
} node;
node nn[10005];


int cmp(const void *a,  const void *b) {
    return (*(node*)a).begin - (*(node*)b).begin;
}

int minTaps(int n, int* ranges, int rangesSize){
    for (int i = 0; i < rangesSize; ++i) {
        nn[i].begin = i - ranges[i];
        nn[i].end = i + ranges[i];
    }
    qsort(nn, rangesSize, sizeof(node), cmp);
    
    int i = 0;
    int j = 0;
    int tmp = 0;
    int ret = 0;
    int newBegin = 0;
    int maxLen = 0;
    while (newBegin < n) {
        maxLen = 0;
        while (i < rangesSize && nn[i].begin <= newBegin) {
            tmp = nn[i].end - newBegin;
            if (tmp > maxLen) {
                maxLen = tmp;
                j = i;
            }
            ++i;
        }
        
        if (maxLen == 0) {
            return -1;
        }
        
        ++ret;
        newBegin = nn[j].end;
    }
    
    return ret;
}

```