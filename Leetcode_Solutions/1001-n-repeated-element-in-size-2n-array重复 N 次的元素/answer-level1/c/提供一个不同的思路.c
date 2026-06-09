int repeatedNTimes(int* A, int ASize){
    for(int i=1;i<ASize-1;i++)
    {
        if(A[i-1]==A[i+1]) return A[i-1];
        else if(A[i]==A[i+1]) return A[i];
        else if (A[i]==A[i-1]) return A[i];
    }
    return ;
}
