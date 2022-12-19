```
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int totalSize = m + n;

    while (m != 0 || n != 0) {
        if (m == 0) {
            while (n != 0) A[--totalSize] = B[--n];
            break;
        } else if (n == 0) break;
        
         A[--totalSize] = A[m - 1] > B[n - 1] ? A[--m] : B[--n];
    }
}
```
