```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int a,i;
    long n; //n如果用int,target为50000多的时候n*(n-1)会越界
    int** res=(int**)malloc(sizeof(int*) * (2*target));
    int* col = (int*)malloc(sizeof(int) * (2*target));
    int m=0;
    for (n=target;n>=2;n--){
        if (target-n*(n-1)/2<=0) {continue;}
        if ((2*target-n*n+n)%(2*n)==0){
            a=(2*target-n*n+n)/(2*n);
            col[m]=n;
            res[m]= (int*)malloc(sizeof(int)*n);
            for (i=0;i<n;i++){
                res[m][i]=a+i;
            }
            m++;
        }
    }
    *returnSize=m;
    *returnColumnSizes = col;
    return res;
}
```
