### 解题思路
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例:

输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6




1. 将每层格子内容变为柱子高度值
2. 每一层相当于一个数组，  于是可套用84题方案，每层来一遍  

### 代码

```c

/*84题  优化暴力题解*/
int max_rec(int *heighs, int heighSize){
    int i,j,h_min,rec_max=0,rec_max_temp;

    for(i=0;i<heighSize;i++){
        h_min = heighs[i];
        //printf("heighs[%d]=%d \n",i,heighs[i]);
        for(j=i;j<heighSize;j++){
            h_min = h_min < heighs[j] ? h_min : heighs[j];
            rec_max_temp = h_min * (j-i+1);
            rec_max = rec_max > rec_max_temp ? rec_max : rec_max_temp;
        }
    }
    return rec_max;
}



int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    int i,j,k,temp_max, max = 0;
    int **arr = (int **)malloc(matrixSize * sizeof(int *));

    if(matrixSize ==0 ) return 0;

    for(i=0;i<matrixSize;i++){
        arr[i] = (int *)malloc(matrixColSize[0] * sizeof(int));
        memset(arr[i],0,matrixColSize[0]*sizeof(int));
    }

    /*数组第一行单独初始化方便些*/
    for(i=0;i<matrixColSize[0];i++){
        if(matrix[0][i] == '1')
            arr[0][i] = 1; 
    }

    /*转换成二维数组，并且里面存放的是柱状高度
      从第二行开始*/
    for(i=1;i<matrixSize;i++){
        for(j=0;j<matrixColSize[0];j++){
            /*连续则+1， 不连续则为0*/
            if(matrix[i][j] == '1')
                arr[i][j] = arr[i-1][j] + 1;
            //printf("%d ",arr[i][j]);
        }
        //printf("\n");
    }

    for(i=0;i<matrixSize;i++){
        temp_max = max_rec(arr[i],matrixColSize[0]);
        max = max > temp_max ? max : temp_max;
    }

    return max;
}
```