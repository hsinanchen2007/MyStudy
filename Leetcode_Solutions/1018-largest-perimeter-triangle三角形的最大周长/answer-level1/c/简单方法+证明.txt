### 解题思路
1. 先考虑一个升序的数组, 对于数组中某三个数成立A + B > C(满足三角形有面积条件)(A,B < C)
2. 那么对于 Array[index_C - 1] + Array[index_C - 2] > C 也一定成立, 因为Array[index_C - 1] + Array[index_C - 2] >= A + B
3. 因为Array[index_C - 1] + Array[index_C - 2], 是小于C的任意两个数之和中最大的, 因此最大的组合在有序数组中一定是相邻的三个数
4. 那么我们只需要从大到小找到满足条件的最大的C就可以了

### 代码

```c
int compare(const void* a, const void* b){
    return *((int *)a) - *((int *)b);
}
int largestPerimeter(int* A, int ASize){
    //快排
    qsort(A,ASize,sizeof(int),compare);

    //从大到小寻找C
    for (int i = ASize - 3; i>=0; --i){
        if ((A[i] + A[i+1]) > A[i+2]){
            return A[i]+A[i+1]+A[i+2];
        }
    }
    return 0;
}
```