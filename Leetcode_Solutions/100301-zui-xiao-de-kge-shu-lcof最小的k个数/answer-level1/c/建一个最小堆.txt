### 解题思路
如题。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void insert2Heap(int *minheap, int size, int *idx, int val) {
    minheap[*idx] = val;
    if (*idx == 0) {
        *idx = *idx + 1;
        return;
    }

    int child = *idx;
    int father = (child-1)/2;
    while (child > 0 && minheap[father] > val) {
        minheap[child] = minheap[father];
        child = father;
        father = (child-1)/2;
    }
    minheap[child] = val;

    *idx = *idx+1;
    return;
}

int delHeapRoot(int *minheap, int size, int *idx) {
    int val = minheap[0];
    int last = minheap[*idx-1];
    int father = 0;

    int child = 2*father+1;
    while (child <= *idx-1) { 
        if (child+1 <= *idx-1 && minheap[child+1] < minheap[child]) child++;
        if (last < minheap[child]) break;
        minheap[father] = minheap[child];
        father = child;
        child = 2*father+1;
    }
    minheap[father] = last;

    *idx = *idx -1;
    return val;
}


int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if (!arr || arrSize == 0 || !returnSize) {
        *returnSize = 0;
        return NULL;
    }
    int minheap[arrSize];
    int minheapIdx = 0;
    (void)memset(minheap, 0, sizeof(int) * arrSize);

    for (int i=0; i < arrSize; i++) {
        insert2Heap(minheap, arrSize, &minheapIdx, arr[i]);
    }

    int *ans = (int*) malloc(sizeof(int) * k);
    int ansIdx = 0;
    for (int i = 0; i < k; i++) {
        ans[ansIdx++] = delHeapRoot(minheap, arrSize, &minheapIdx);
    }

    *returnSize = ansIdx;
    return ans;
}
```