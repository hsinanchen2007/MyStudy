
先排序，然后遍历数组查看当前数与下一个数的差，然后补齐下一个数比当前数大1.
```
public int minIncrementForUnique(int[] A) {
    Arrays.sort(A);
    int actions = 0;
    for(int i=0; i< A.length - 1;i++) {
        if(A[i] >= A[i+1]) {
            actions +=A[i] - A[i+1] + 1;
            A[i+1] = A[i] + 1;
        }
    }
    return actions;
}
```
