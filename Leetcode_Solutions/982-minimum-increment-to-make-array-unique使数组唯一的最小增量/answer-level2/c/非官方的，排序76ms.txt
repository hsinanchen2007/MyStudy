### 解题思路
1.先统计
2.在将数据进行排序。
3.从小到达遍历数组，如果遇见冲突的，从上次的空闲节点出遍历找一个空闲节点，记录距离

### 代码

```c

#define MAX_NUM_VAL 80000
int IntCmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int minIncrementForUnique(int* A, int ASize){
    int cntMap[MAX_NUM_VAL + 1] = {0};
    int maxNum = 0;
    for (int i = 0; i < ASize; i++) {
        cntMap[A[i]]++;
        if (A[i] > maxNum) {
            maxNum = A[i];
        }
    }
    int ans = 0;
    qsort(A, ASize, sizeof(int), IntCmp);
    int curPos = 0;
    int cur = 0;
    for (int i = 0; i < ASize; i++) {
        if (cntMap[A[i]] == 1) {
            continue;
        }
        cntMap[A[i]]--;
        if (cur < A[i]) {
            cur = A[i];
        }
        while (cur < MAX_NUM_VAL && cntMap[cur] != 0) {
            cur++;
        }
        ans += (cur - A[i]);
        cntMap[cur] = 1;
    }
    return ans;
}
```