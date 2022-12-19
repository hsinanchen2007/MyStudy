### 解题思路
快速排序+hash表置标记.
快速排序比较耗时，影响了执行时间。

### 代码

```c

#define HASH_VALUE_SIZE 50000   // 注意此值要大于40000, 如果最大数正好为40000，那么往后操作还要向后累加的
int gHash[HASH_VALUE_SIZE] = { 0 };

int Compare(void *a, void *b) 
{
    return (*(int *)a) > (*(int *)b);   // 升序排序
}

int GetNextAvailableNum(int a)
{   
    for (int i = a + 1; i < HASH_VALUE_SIZE; i++) {
        if (gHash[i] == 0) {
            return i;
        }
    }
    return -1;
}

int minIncrementForUnique(int* A, int ASize){
    if (A == NULL) {
        return 0;
    }
    // init
    memset(gHash, 0, sizeof(gHash));
    qsort(A, ASize, sizeof(int), Compare);  // 快速排序，升序
    int sum = 0;
    for (int i = 0; i < ASize; i++) {
        if (gHash[A[i]] == 0) { // A[i]不重复
            gHash[A[i]] = 1;    // Hash表置标记
        } else {    // 重复元素
            int targetNumber = GetNextAvailableNum(A[i]);   // 找下一个不重复数：目标数
            if (targetNumber != -1) {
                gHash[targetNumber] = 1;    // 更新哈希表，置标记
                sum += targetNumber - A[i]; // 累加操作次数
            } else {    // 超过数组限制大小，防止数组越界
                printf("error %d\n", A[i]);
            }
        }        
    }   
    return sum;
}
```