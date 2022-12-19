将2N个数分成N组，两两比较，若仍未找到，则任选其中两组，必有2个数相同，再额外比较两次即可找到。
```
int repeatedNTimes(int* A, int ASize){
    for(int i=0;i<ASize/2;i++){
        if(A[i]==A[i+ASize/2])
            return A[i];
    }
    return A[0]==A[1]?A[0]:A[1]==A[ASize/2]?A[1]:A[ASize/2+1];
}
```
