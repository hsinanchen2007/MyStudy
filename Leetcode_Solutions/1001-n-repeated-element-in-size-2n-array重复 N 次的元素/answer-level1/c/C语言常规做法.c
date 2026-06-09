```c
int repeatedNTimes(int* A, int ASize){
    int i,j;
    for(i=0;i<ASize;i++)
        for(j=i+1;j<ASize;j++)
            if(A[j]==A[i]) return A[i];
    return 0;
}
```