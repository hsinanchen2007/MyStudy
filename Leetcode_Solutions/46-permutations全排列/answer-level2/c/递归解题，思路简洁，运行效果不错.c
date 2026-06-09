### 解题思路
思路是递归，不过有几个坑需要注意；
坑一、输入输出的内存到底是在哪申请，题解使用output外部申请；
坑二、一直没搞明白returnColumnSizes该怎么赋值，其实功能大概二十分钟就写对了，愣是返回错误，加了无数打印，发现不是递归的问题。
![全排列.JPG](https://pic.leetcode-cn.com/b39e6865c9077da41c5d6abfd731a13d19c7c7bae5a27da2f37604e50bca84b0-%E5%85%A8%E6%8E%92%E5%88%97.JPG)


### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int arraySize(int number){
    if(number==1)return 1;
    return number*arraySize(number-1);
}
void DFS(int**output, int* input, int inputSize){
    int outputSize = arraySize(inputSize);
    if(inputSize==1){
        output[0][0] = input[0];
        return;
    }
    int tempInputSize = inputSize - 1;
    int *tempInput = (int*)malloc(sizeof(int)*tempInputSize);
    int tempOutputSize = arraySize(tempInputSize);
    int **tempOutput = (int**)malloc(sizeof(int*)*tempOutputSize);
    for(int i=0;i<tempOutputSize;i++){
        tempOutput[i] = (int*)malloc(sizeof(int)*tempInputSize);
    }
    for(int i=0;i<inputSize;i++){
        for(int j=0;j<i;j++){
            tempInput[j] = input[j];
        }
        for(int j=i;j<tempInputSize;j++){
            tempInput[j] = input[j+1];
        }
        DFS(tempOutput,tempInput,tempInputSize); 
        for(int j=0;j<tempOutputSize;j++){
            output[i*tempOutputSize+j][0] = input[i];
            for(int k=0;k<tempInputSize;k++){
                output[i*tempOutputSize+j][k+1] = tempOutput[j][k];
            }
        }
    }
    free(tempInput);
    for(int j=0;j<tempOutputSize;j++){
        free(tempOutput[j]);
    }
    free(tempOutput);
    return;
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    (*returnSize) = arraySize(numsSize);
    int** returnArray = (int**)malloc(sizeof(int*)*(*returnSize));
    *(returnColumnSizes) = (int*)malloc(sizeof(int)*(*returnSize));
    for(int i=0;i<(*returnSize);i++){
        returnArray[i] = (int*)malloc(sizeof(int*)*numsSize);
        *(*(returnColumnSizes)+i) = numsSize;
    }
    DFS(returnArray,nums,numsSize);
    return returnArray;
}
```