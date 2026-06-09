直接大小比较合并成一个数组赋给Ａ
```cpp
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int sum = m + n;
    int i = 0, j = 0;
    int *temp = (int *)malloc(sizeof(int) * sum);
    int k = 0;
    while(i < m && j < n) {
        if(A[i] < B[j]) temp[k ++] = A[i++];
        else {
            temp[k++] = B[j++];
        }
    }
    while(i < m) temp[k++] = A[i++];
    while(j < n)temp[k++] = B[j++];
    for(int i = 0, j = 0; i < sum; i++, j++) {
        A[i] = temp[j];
    }
}
```