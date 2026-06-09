```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int flag[1024]={0};
void dfs(int *nums,int numsSize,int arr[],int **res,int i,int m,int *ind){
    if(m==numsSize){
        for(int i=0;i<numsSize;i++){
            res[*ind][i]=arr[i];
        }
        (*ind)++;
        return ;
    }
    for (int i=0;i<numsSize;i++){
        if(flag[i]==1) continue;
        arr[m]=nums[i];
        flag[i]=1;
        dfs(nums,numsSize,arr,res,i,m+1,ind);
        flag[i]=0;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize=0;
    if (numsSize==0) return 0; 
    int count=1,k=1;
    for(k=1;k<=numsSize;k++) count=count*k;

    int **res=(int **)malloc(sizeof(int *)*count);
    *returnColumnSizes=(int *)malloc(sizeof(int)*count);

    for(int i=0;i<count;i++){
        res[i]=(int *)malloc(sizeof(int)*numsSize);
        (*returnColumnSizes)[i]=numsSize;
    }
    *returnSize=count;

    int arr[numsSize],ind=0;
    dfs(nums,numsSize,arr,res,0,0,&ind); //ind为传址参数，因为在dfs中，ind一直在变！！！
    return res;

}
```
