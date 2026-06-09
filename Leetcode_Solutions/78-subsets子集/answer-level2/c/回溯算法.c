### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void subsetsProc(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int **res, int *dummy, int columnSize){
    int i;
    for(i=0;i<numsSize;i++){
        if(columnSize>0&&nums[i]<=dummy[columnSize-1]){
            continue;
        }
        //printf("%d %d %d\n",*returnSize,columnSize,nums[i]);
        dummy[columnSize]=nums[i];
        //这里的columnSize是从0开始的所以需要加1
        //因为res[i]的每个后缀都是'\0',因此不需要再加1
        memcpy(res[(*returnSize)],dummy,sizeof(int)*(columnSize+1));
        (*returnColumnSizes)[(*returnSize)]=columnSize+1;
        (*returnSize)++;
        subsetsProc(nums, numsSize, returnSize, returnColumnSizes, res, dummy, columnSize+1);
    }
    return;
    //空集
}

int cmp(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnColumnSizes=(int *)malloc(sizeof(int)*10000);
    (*returnColumnSizes)[0]=0;
    *returnSize=1;
    //if(nums==NULL||numsSize==0){
    //    return 0;
    //}
    qsort(nums,numsSize,sizeof(int),cmp);
    /*
    int j;
    for(j=0;j<numsSize;j++){
        printf("%d ",nums[j]);
    }
    */
    int **res=(int **)malloc(sizeof(int *)*10000);
    int i;
    for(i=0;i<10000;i++){
        res[i]=(int *)malloc(sizeof(int)*1000);
    }
    for(i=0;i<10000;i++){
        memset(res[i],'\0',sizeof(int)*1000);
    }
    int *dummy=(int *)malloc(sizeof(int)*1000);
    memset(dummy,'\0',sizeof(int)*1000);
    subsetsProc(nums, numsSize, returnSize, returnColumnSizes, res, dummy, 0);
    free(dummy);
    //printf("%d",*returnSize);
    return res;
}
//ERROR
//[1,2,3,4,5,6,7,8,10,0]
//我设置的1000过小
```