**这个思路参考了大名鼎鼎的甜姨，外加上一些自己的理解。**

![IMG_20200407_1322482.jpg](https://pic.leetcode-cn.com/35916a5df2874aaab6f412c80abd9b8f93a012b9c33d5b99cb8d1cf53b086e54-IMG_20200407_1322482.jpg)
**想象一下你有一本书，你把这本书沿对象线来了一次对称翻转，那么上面的字体必然也会翻转，所以说之后你还要再把这本书沿轴对称镜像一下，即可得到旋转九十度的结果**


```
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i=0,j=0,t=0;
    while( i < matrixSize ){
        j = i+1;
        while( j <matrixSize ){
            t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
            j++;
        }
        i++;
    }
    i = 0;
    while( i < matrixSize ){
        j = 0;
        while( j < matrixSize / 2 ){
            t = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize-j-1];
            matrix[i][matrixSize-j-1] = t;
            j++;
        }
        i++;
    }
}
```
