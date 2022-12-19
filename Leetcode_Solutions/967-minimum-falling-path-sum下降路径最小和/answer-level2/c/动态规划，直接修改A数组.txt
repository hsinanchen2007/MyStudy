执行用时：16ms
内存消耗：6.2MB
```
int min(int a, int b){
    return a<b? a:b;
}
int minFallingPathSum(int** A, int ASize, int* AColSize){
    int i,j;
    for(i=1; i<ASize; i++){
        A[i][0] += min(A[i-1][0], A[i-1][1]);
        for(j=1; j<AColSize[i]-1; j++) A[i][j] += min(A[i-1][j-1], min(A[i-1][j],A[i-1][j+1]));
        A[i][j] += min(A[i-1][j-1], A[i-1][j]);
    }
    int m = A[ASize-1][0];
    for(i=1; i<AColSize[ASize-1]; i++) m = min(A[ASize-1][i], m);
    return m;
}
```
