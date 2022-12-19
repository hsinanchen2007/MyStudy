### 解题思路
一道典型的排序题，这道题最多算简单
1.先进行小到大的排序；
2.从小到大进行遍历，如果当前数值比前一个小或者相等，那么我们就将当前值增加到比前一个值大1；需要移动差值+1次；
3.直接到循环尾部，累加count值。

### 代码

```c
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int minIncrementForUnique(int* A, int ASize){
    int count = 0;
    qsort(A, ASize, sizeof(int),compare);
    int i;
    for(i = 1; i < ASize; i++) {
    //    printf(" A [%d] %d\n", i, A[i]);
        if (A[i] <= A[i - 1]) {
            count += A[i - 1] - A[i] + 1;
            A[i] = A[i - 1] + 1;
        } 
   //     printf(" new A [%d] %d\n", i, A[i]);
    }

    return count;
}
```