```
int comp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int minIncrementForUnique(int* A, int ASize){
    int nums = 0;
    
    qsort(A, ASize, sizeof(int), comp);

        
    for(int i = 1; i < ASize; i++){
        if(A[i] > A[i-1]){
            continue;
        }
        
        if(A[i] <= A[i-1]){
            int temp = A[i-1]-A[i]+1;
            A[i] += temp;
            nums += temp;
        }
    }
    return  nums;
}


```
