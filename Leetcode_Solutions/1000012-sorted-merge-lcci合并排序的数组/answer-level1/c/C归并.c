### 解题思路
直接看代码

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i = m - 1;
    int j = n - 1;
    int index = m + n - 1;
    
    while ((i >= 0) && (j >= 0) && (index >= 0)){
        if(A[i] > B[j]){
            A[index--] = A[i--];
        } else {
            A[index--] = B[j--];  
        }
    }

    while ((i >= 0) && (index >= 0)) {
        A[index--] = A[i--];
    }

    while ((j >= 0) && (index >= 0)) {
        A[index--] = B[j--];
    }

    return;
}
```