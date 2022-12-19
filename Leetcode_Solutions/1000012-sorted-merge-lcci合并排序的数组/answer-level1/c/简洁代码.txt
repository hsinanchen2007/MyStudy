void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i = m - 1, j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0) {
        A[k--] = A[i] > B[j] ? A[i--] : B[j--];
    }

    while (i >= 0) {
        A[k--] = A[i--];
    }

    while (j >= 0) {
        A[k--] = B[j--];
    }
    
    return A;
}