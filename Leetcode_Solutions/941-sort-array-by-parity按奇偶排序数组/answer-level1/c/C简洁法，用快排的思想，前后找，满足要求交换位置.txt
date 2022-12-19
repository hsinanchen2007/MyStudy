int* sortArrayByParity(int* A, int ASize, int* returnSize){
    *returnSize=ASize;
    int i=0,j=ASize-1,temp;
    while(i<j){
        while(A[j]%2==1&&i<j){j--;}
        while(A[i]%2==0&&i<j){i++;}
        temp=A[j];
        A[j]=A[i];
        A[i]=temp;
    }
    return A;
}