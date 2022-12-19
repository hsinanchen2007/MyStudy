```
int* sortArrayByParity(int* A, int ASize, int* returnSize){ // Do by myself
    int i, j, temp;
    for(i = 0; i < ASize; i++){
        if(A[i]%2==0) continue;
        else{
            for(j = i; j < ASize-1; j++){
                if(A[j+1]%2==0){
                    temp = A[j+1];
                    A[j+1] = A[i];
                    A[i] = temp;
                    break;
                }
            }
        }
    }
    *returnSize = ASize;
    return A;
```