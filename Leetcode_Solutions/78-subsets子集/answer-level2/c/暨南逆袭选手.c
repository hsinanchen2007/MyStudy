### 解题思路
典型的回溯法，剪枝有点搞心态，不够细致！
对于当前节点有两种情况：
1. 作为一种一个子集的结尾添加到结果集中
2. 作为一个子集中的元素添加进去，继续往递归树向下添加。
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//对于当前节点有两种情况，
//1.作为一种一个子集的结尾添加到结果集中
//2.作为一个子集中的元素添加进去，继续往递归树向下添加。
void dfs(int **retArray, int *currentArray,int addLen,int start, int index,int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(index == numsSize ) {
        return; 
    }
    for( int i = start; i < numsSize; i++ ) {
        addLen++;
        currentArray[index] = nums[i];
        retArray[*returnSize] = (int *) malloc ( sizeof(int) * addLen);
        (*returnColumnSizes)[*returnSize] = addLen;
        for( int j = 0; j < addLen; j++){//the first reslut
            retArray[*returnSize][j] = currentArray[j];
        }
        (*returnSize)++;// the reslut add one
        
        //the second reslut
        dfs( retArray, currentArray, addLen, i+1, index+1, nums, numsSize, returnSize, returnColumnSizes);
        addLen--;
    }
 }
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **retArray = (int **) malloc ( sizeof(int *) * 1024 );
    *returnColumnSizes = (int *) malloc ( sizeof(int) * 1024 );
    int *currentArray = (int *) malloc ( sizeof(int) * numsSize);
    int addLen = 0;
    int start = 0;
    int index = 0;
    *returnSize = 0;
    dfs( retArray, currentArray, addLen, start, index, nums, numsSize, returnSize, returnColumnSizes); 

    retArray[*returnSize] = (int *) malloc ( sizeof( int ));
    retArray[*returnSize][0] = "";
    (*returnColumnSizes)[*returnSize] = 0;
    (*returnSize)++;
    return retArray;
}
```