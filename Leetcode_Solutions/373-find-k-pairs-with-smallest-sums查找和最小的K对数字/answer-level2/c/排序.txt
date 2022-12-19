```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct {
    int a, b, sum;
} Node;

int cmp(const void *a, const void *b)
{
    return ((Node *)a)->sum < ((Node *)b)->sum ? -1 : 1;
}
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes){
    Node *arr = (Node *) malloc(sizeof(Node) * nums1Size * nums2Size);
    int cnt = 0;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            arr[cnt].a = nums1[i];
            arr[cnt].b = nums2[j];
            arr[cnt++].sum = nums1[i] + nums2[j];
        }
    }
    qsort(arr, cnt, sizeof(Node), cmp);
    *returnSize = k < cnt ? k : cnt;
    int **res = (int **) malloc(sizeof(int *) * (*returnSize));
    *returnColumnSizes = (int *) malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        res[i] = (int *) malloc(sizeof(int) * 2);
        res[i][0] = arr[i].a, res[i][1] = arr[i].b;
        (*returnColumnSizes)[i] = 2;
    }
    free(arr);
    return res;
}
```
