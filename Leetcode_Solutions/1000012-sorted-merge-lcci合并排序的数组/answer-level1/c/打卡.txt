### 解题思路
此处撰写解题思路

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i = 0 , j = 0;
    for(int i = 0 ; i<BSize ; i++){
        for( j = j; j<ASize ; j++){
            if(B[i]<=A[j]){
                int temp2 = 0 , temp1 = A[j]; 
                for(int k = j; k<ASize-1; k++){
                    temp2 = temp1;
                    temp1 = A[k+1];
                    A[k+1] = temp2;
                }
                A[j] = B[i] ; m++; break;
            }
            else if(j+1>m){
                A[j] = B[i]; m++;
                break;
            }
        }
    }
}
```