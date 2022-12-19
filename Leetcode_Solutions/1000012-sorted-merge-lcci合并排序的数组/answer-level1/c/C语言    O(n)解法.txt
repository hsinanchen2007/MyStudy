题目明确A数组空间够用，所以直接使用数组A存放结果，为了不覆盖原来A的元素所有从后往前遍历。维护一个结果数组索引index，A数组待排元素索引i，B数组待排元素索引j，之后就是归并的操作。代码如下

```
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int index = m+n-1;
    int i = m-1;
    int j = n-1;

    while(i>=0 && j>=0 && index>=0){
        if(A[i] > B[j]){
            A[index--] = A[i--];
        }else{
            A[index--] = B[j--];  
        }
    }

    while(i>=0 && index>=0){
        A[index--] = A[i--];
    }
    while(j>=0 && index>=0){
        A[index--] = B[j--];
    }
}
```
