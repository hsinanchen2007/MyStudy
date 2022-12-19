
### 代码

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int i,j;   
    int *res=(int *)malloc(TSize*sizeof(int));
    res[TSize-1]=0;
    for(i=TSize-2;i>=0;i--){
        for(j=i+1;j<=TSize-1;j+=res[j]){
            if(T[i]<T[j]) {
                *(res+i)=j-i;
                break;
            }
            else{
                if(*(res+j)==0) {
                    *(res+i)=0;
                    break;
                }
            }
        }
    }
    *returnSize=TSize;
    return res;

}
```