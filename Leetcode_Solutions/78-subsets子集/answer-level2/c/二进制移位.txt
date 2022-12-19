通过二进制位指示子序列中保存哪些数。
以{1,2,3}为例，三个数，共2^3个子集，for循环从1到7，bit表示就是000到111，那么直接通过比特为指示哪些数保存到子序列中即可，
比如101就是保存{1,3}， 110就是{1,2}……
```c []

/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, j, k;
    int outNum;
    int bitNum;
    int bitCnt = 0;
    int **outPut;
    
    
    outNum = 1 << numsSize;             // n个输入的总子序列个数就是2^n次方
    *returnSize = outNum;
    outPut = (int **)malloc(sizeof(int *) * (outNum));
    returnColumnSizes[0] = (int *)malloc(outNum * sizeof(int));
    for (i = 0; i < outNum; i++) {      
        bitCnt = 0;
        j = 0;
        k = 0;
        bitNum = i;
        while (bitNum) {
            bitCnt += bitNum & 0x01;    // 算出i对应的bit位为1个总个数，就是待申请的内存的大小
            bitNum = bitNum >> 1;       
        }
        returnColumnSizes[0][i] = bitCnt;
        outPut[i] = (int *)malloc(sizeof(int) * bitCnt);
        bitNum = i;
        while (bitNum) {                // i对应bit位为1的地方对应的值也保存在子序列中
            if (bitNum & 0x01) {
                *(outPut[i] + j) = *(nums + k);                
                j++;
            }
            bitNum >>= 1;
            k++;
        } 
    }
    return outPut;
}


```
