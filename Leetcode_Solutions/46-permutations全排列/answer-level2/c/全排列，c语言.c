//int a[n] = {};数组初始化赋值，没有赋值的就会变为，所以这行代码等于全部初始化为0
代码思想：递归dps，借助一个标记数组。
```
void recursion(int i,int j,int* temp,int* sign,int* nums,int numsSize,int* returnSize,int** result){
    temp[i] = nums[j];
    if(i == numsSize-1){
        for(int k=0;k<numsSize;k++){
            result[*returnSize][k] = temp[k];
        }
        (*returnSize)++;
    }else{
        for(int k=0;k<numsSize;k++){
            if(sign[k] == 0){
                sign[k] = 1;
                recursion(i+1,k,temp,sign,nums,numsSize,returnSize,result);
            }
        }
    }
    sign[j] = 0;
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(numsSize<0){
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 1;
    for(int n=numsSize;n>0;n--){
        *returnSize *= n;
    }
    int** result = (int**)malloc(sizeof(int*)*(*returnSize));
    (*returnColumnSizes) = (int*)malloc(sizeof(int)*(*returnSize));
    for(int i=0;i<*returnSize;i++){
        result[i] = (int*)malloc(sizeof(int)*numsSize);
        (*returnColumnSizes)[i] = numsSize;
    }
    *returnSize = 0;
    int sign[numsSize];
    for(int i=0;i<numsSize;i++){
        sign[i] = 0;
    }
    int temp[numsSize];
    for(int i=0;i<numsSize;i++){
        sign[i] = 1;
        recursion(0,i,temp,sign,nums,numsSize,returnSize,result);
    }
    return result;
}
```
