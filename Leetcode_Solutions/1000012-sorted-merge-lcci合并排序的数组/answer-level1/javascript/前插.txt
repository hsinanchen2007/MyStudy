
```
let i = 0, j = 0, k = 0;
    A.splice(m,n);
    while (k < m + n && j < n) {
        if (A[i] < B[j]) {
            A[k++] = A[i++];
        } else {
            A.splice(k, 0, 0);
            A[k++] = B[j++];
            i = k;
        }
    }
    return A;
```
