/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int basicSize = 256;

int g_returnSize = 0;

int **g_ReturnCloun = 0;

int *g_returnColumnSizes = 0;

void addNode(int*nums, int*Per, int numsSize){

    if (g_returnSize == 0){
        g_ReturnCloun = (int **)malloc(sizeof(int*)*basicSize);
        g_returnColumnSizes =(int*)malloc(sizeof(int)*basicSize);
    }
    if(g_returnSize >= basicSize){
        basicSize = 2* basicSize;
        g_ReturnCloun = (int **)realloc(g_ReturnCloun, sizeof(int*)* basicSize);
        g_returnColumnSizes = (int*)realloc(g_returnColumnSizes,sizeof(int)*basicSize);
    }
    int *curNode = (int* )malloc(sizeof(int)*numsSize);
    for(int i=0; i<numsSize; i++){
        curNode[i] = nums[Per[i]];
    }
    g_ReturnCloun[g_returnSize] = curNode;
    g_returnColumnSizes[g_returnSize] = numsSize;
    
    g_returnSize++;
}
bool isExsitInArray(int *Per, int curSize, int index){
    for(int i=0; i<curSize; i++){
        
        if (Per[i] == index){
            return true;
        }
    }
    return false;
}

//怎么返回二维数组！！！！

void myPermute(int*nums, int numsSizes, int curSize, int*Per){

    if (curSize == numsSizes){
        addNode(nums, Per, numsSizes);
        return;
    }
    for(int i=0; i<numsSizes; i++){
        if (false == isExsitInArray(Per, curSize, i)){
            Per[curSize] = i;
            myPermute(nums, numsSizes, curSize+1, Per);
        }
    }
    return;
}




int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int *tempSort = (int *)malloc(sizeof(int)*numsSize);
    memset(tempSort, 0, sizeof(int)*numsSize);
    g_returnSize = 0;
    g_returnColumnSizes = 0;
    g_ReturnCloun = 0;
    myPermute(nums, numsSize, 0, tempSort);
    free(tempSort);
    *returnSize = g_returnSize;
    *returnColumnSizes = g_returnColumnSizes;
    return g_ReturnCloun;
}

