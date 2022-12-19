1. 对A数组从小到大排序
2. 对B数组中每一个数val，有如下处理
- 如果val大于等于A中没有使用的最大数，那么就将A中没有使用的最小数和val对应
- 否则，在A数组中找到第一个比val大的且没有使用的数和val进行对应
3. 查找时需要使用二分查找，否则会超时

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NULL_PTR (0)
#define TRUE (1)
#define FALSE (0)

#define MAX_SIZE (10010)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int g_visit[MAX_SIZE];

int BinarySearch(int *A, int ASize, int val)
{
    int left = 0;
    int right = ASize - 1;
    int mid;
    while (left <= right) {
        //printf("left = %d right = %d\n", left, right);
        mid = (left + right) >> 1;
        if (val > A[mid]) {
            left = mid + 1;
        } else if (val < A[mid]) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    //printf("left = %d right = %d\n", left, right);
    return MAX(left, right);
}

int CmpFunc(const void *a, const void *b)
{
    int ca = (*(int*)a);
    int cb = (*(int*)b);
    if (ca > cb) {
        return 1;
    } else if (ca < cb) {
        return -1;
    } else {
        return 0;
    }
}

void GetIndex(int *A, int ASize, int val, int *index)
{
    int i;
    int maxAVal = -1;
    int startIdx;
    for (i = ASize - 1; i >= 0; i--) {
        if (g_visit[i] == FALSE) {
            maxAVal = A[i];
            break;
        }
    } 
    if (val >= maxAVal) {
        for (i = 0; i <= ASize - 1; i++) {
            if (g_visit[i] == FALSE) {
                *index = i;
                g_visit[i] = TRUE;
                return;
            }
        }        
    } else {
        startIdx = BinarySearch(A, ASize, val);
        for (i = startIdx; i <= ASize - 1; i++) {
            if ((g_visit[i] == FALSE) && (A[i] > val)) {
                g_visit[i] = TRUE;
                *index = i;
                return;
            }
        }
    }
}

int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize)
{
    int i;
    int index;
    int *ret = (int*)malloc(sizeof(int) * ASize);
    if ((A == NULL_PTR) || (B == NULL_PTR)) {
        *returnSize = 0;
        return 0;
    }
    qsort(A, ASize, sizeof(int), CmpFunc);
    for (i = 0; i < ASize; i++) {
        g_visit[i] = FALSE;
    }
    for (i = 0; i < BSize; i++) {
        GetIndex(A, ASize, B[i], &index);
        ret[i] = A[index];
    }
    *returnSize = ASize;    
    return ret;
}
```
