### 解题思路
递归不停的加,如果满足和为目标就记录下来，回溯在添加别的....
例如2+2+2+2不满足，回溯2+2+2+3满足，回溯2+2+2+6   2+2+2+7     2+2+3+3   2+2+3+6......
剪枝：其实可以通过将数组排序，减少不必要的一些递归。
### 代码

```c

void recursion(int i,int* candidates,int candidatesSize,int target,int** result,int* returnSize,int** returnColumnSizes,int temp,int z){
    for(int j=i;j<candidatesSize;j++){
        if(temp+candidates[j] == target){
            result[*returnSize][z] = candidates[j];
            (*returnColumnSizes)[*returnSize] = z+1;
            *returnSize += 1;
            result[*returnSize] = (int*)malloc(sizeof(int)*target);
            for(int k=0;k<z;k++){
                result[*returnSize][k] = result[(*returnSize)-1][k];
            }
        }else if(temp+candidates[j] < target){
            result[*returnSize][z] = candidates[j];
            recursion(j,candidates,candidatesSize,target,result,returnSize,returnColumnSizes,temp+candidates[j],z+1);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(candidatesSize < 1){
        return NULL;
    }
    int** result = (int**)malloc(sizeof(int*)*9999);
    *returnColumnSizes = (int*)malloc(sizeof(int)*9999);
    result[*returnSize] = (int*)malloc(sizeof(int)*target);
    recursion(0,candidates,candidatesSize,target,result,returnSize,returnColumnSizes,0,0);
    //for(int i=0;i<candidatesSize;i++)
    //    recursion(i,candidates,candidatesSize,target,result,returnSize,returnColumnSizes,0,0);
    //当我在combinationSum函数中调用递归的时候，我用for循环调用递归，并且没有在for循环中添加每个组合的第一个数字，而是企图在for循环调用的递归中添加第一个数字，导致了重复递归，得到了一个奇怪的答案[[2,2,3],[7],[7],[7],[7]]。实际上不用for循环调用递归，或者如果用for循环调用递归应该在for循环中添加第一个数字。
    return result;
}
```