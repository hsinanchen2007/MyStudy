BFS遍历两遍。先把所有的0都放进队列中（第一遍），然后一个个出列，每出列一个都检查旁边有没有1，如果有的话就把1放进队列中，再把原来1的位置改成0，重复这个过程直到队列为空（第二遍）。
![image.png](https://pic.leetcode-cn.com/3f32e7abd7ee78fa82863e33936e604dacc8a5f0fe726079f8fe2ab47590732e-image.png)



```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int qu[10005][2];//(qu[x][0],qu[x][1])是一个坐标
    int tail = 0;
    int head = 0;
    int i, j, x, y, size;
    *returnSize = matrixSize;
    int **reval = (int**)malloc(sizeof(int*) * matrixSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * matrixSize);
    for(i = 0; i < matrixSize; i++){
        reval[i] = (int*)malloc(sizeof(int) * matrixColSize[i]);
        (*returnColumnSizes)[i] = matrixColSize[i];
        for(j = 0; j < matrixColSize[i]; j++)
        {
            if(matrix[i][j] == 0){//将matrix里的所有0放入队列中
                qu[tail][0] = i;
                qu[tail++][1] = j;
            }
        }
    }
    int layer = 0;//层数
    while(head != tail){
        size = tail-head;
        for(i = 0; i < size; i++){
            x = qu[head][0];
            y = qu[head++][1];
            reval[x][y] = layer;
            if(x>0 && matrix[x-1][y]==1){qu[tail][0]=x-1;qu[tail++][1]=y;matrix[x-1][y] = 0;}
            if(x<matrixSize-1 && matrix[x+1][y]==1){qu[tail][0]=x+1;qu[tail++][1]=y;matrix[x+1][y] = 0;}
            if(y>0 && matrix[x][y-1]==1){qu[tail][0]=x;qu[tail++][1]=y-1;matrix[x][y-1] = 0;}
            if(y<matrixColSize[x]-1 && matrix[x][y+1]==1){qu[tail][0]=x;qu[tail++][1]=y+1;matrix[x][y+1] = 0;}
        }
        layer++;
    }
    return reval;
}
```
- 做了一些修改，不用新建reval的数组，直接再matrix上面修改
```
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int qu[10005][2];//(qu[x][0],qu[x][1]) is a pair pf coordinate
    int tail = 0;
    int head = 0;
    int max_num = 0x7fffffff;
    int i, j, x, y, size;
    *returnSize = matrixSize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * matrixSize);
    for(i = 0; i < matrixSize; i++){
        (*returnColumnSizes)[i] = matrixColSize[i];
        for(j = 0; j < matrixColSize[i]; j++)
        {
            if(matrix[i][j] == 0){
                qu[tail][0] = i;
                qu[tail++][1] = j;
            }else{
                matrix[i][j] = max_num;
            }
        }
    }
    int layer = 0;
    while(head != tail){
        size = tail-head;
        for(i = 0; i < size; i++){
            x = qu[head][0];
            y = qu[head++][1];
            if(x>0 && matrix[x-1][y]==max_num){qu[tail][0]=x-1;qu[tail++][1]=y;matrix[x-1][y] = layer+1;}
            if(x<matrixSize-1 && matrix[x+1][y]==max_num){qu[tail][0]=x+1;qu[tail++][1]=y;matrix[x+1][y] = layer+1;}
            if(y>0 && matrix[x][y-1]==max_num){qu[tail][0]=x;qu[tail++][1]=y-1;matrix[x][y-1] = layer+1;}
            if(y<matrixColSize[x]-1 && matrix[x][y+1]==max_num){qu[tail][0]=x;qu[tail++][1]=y+1;matrix[x][y+1] = layer+1;}
        }
        layer++;
    }
    return matrix;
}
```

