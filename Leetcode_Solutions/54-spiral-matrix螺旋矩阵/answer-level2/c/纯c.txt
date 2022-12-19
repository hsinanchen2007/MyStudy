### 解题思路
标记上下左右四个方向分别为0，1，2，3，上下左右极限分别为up,down,left,right

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize==0||*matrixColSize==0){*returnSize=0;return NULL;}
    int all=matrixSize*(*matrixColSize);
    int* result=(int*)malloc(all*sizeof(int));
    int up=0,left=0,right=*matrixColSize-1,down=matrixSize-1;
    int direction=0,m=0,n=0;
    for(int i=0;i<all;i++){
        switch(direction){
            case 0: result[i]=matrix[m][n++];
                    if(n==right+1){
                        up++;
                        n--;
                        m++;
                        direction++;
                    }
                    break;
            case 1: result[i]=matrix[m++][n];
                    if(m==down+1){
                        right--;
                        n--;
                        m--;
                        direction++;
                    }
                    break;
            case 2: result[i]=matrix[m][n--];
                    if(n==left-1){
                        down--;
                        n++;
                        m--;
                        direction++;
                    }
                    break;
            case 3: result[i]=matrix[m--][n];
                    if(m==up-1){
                        left++;
                        n++;
                        m++;
                        direction=0;
                    }
        }
    }
    *returnSize=all;
    return result;
}
```