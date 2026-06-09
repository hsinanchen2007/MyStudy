### 解题思路
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]




注意体会leetcode风格 各参数含义

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int i,j;
    //指针的指针， 即是分配1或多个指针。   后面每个指针指向的内存还需分配
    int **res = (int *)malloc(numRows * sizeof(int *));
    
    //returnColumnSizes 其实是一维数组的取地址
    //*returnColumnSizes 相当于 returnColumnSizes[0],
    *returnColumnSizes = (int *)malloc(numRows * sizeof(int));
    *returnSize = numRows;
    for(i=1;i<=numRows;i++){
        res[i-1] = malloc(i*sizeof(int));
        (*returnColumnSizes)[i-1] = i;
        for(j=0;j<i;j++){
            if(j==0 || j==(i-1)){
                res[i-1][j] = 1;
            }else{
                res[i-1][j] = res[i-2][j-1] +res[i-2][j];  
            }
        }
    }
    return res;
}
```