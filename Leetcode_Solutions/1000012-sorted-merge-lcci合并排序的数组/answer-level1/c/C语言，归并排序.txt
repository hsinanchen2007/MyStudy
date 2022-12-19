void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int Aindex = m - 1;
    int Bindex = n - 1;
    int cur = ASize - 1;
    int i;
    while (Bindex >= 0 && Aindex >= 0) {
        if (A[Aindex] < B[Bindex]) {
            A[cur--] = B[Bindex--];
        } else {
            A[cur--] = A[Aindex--];
        }
    }
    if (Aindex == -1) {
        for (i = 0; i <= Bindex; i++) {
            A[i] = B[i];
        }
    }
}