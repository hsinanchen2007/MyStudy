```
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrix == NULL || matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    * returnSize=matrixSize*(* matrixColSize);
    int *ret=(int *)malloc(sizeof(int)*(* returnSize));
    int k=0;

    int boundary[4]={0,0,matrixSize-1,(* matrixColSize)-1};
    //边界数组，表示当前的边界，首行，首列，末行，末列

    int direction=0;
    //方向判别flag，//0:向右；1：向下；向前：left；3：向上
    while(boundary[3]-boundary[1]!=-1&&boundary[2]-boundary[0]!=-1){
        int i=0;
        switch(direction){
            case 0:
                for(i=boundary[1];i<=boundary[3];i++)
                    ret[k++]=matrix[boundary[0]][i];
                boundary[0]++;  
                break;
            case 1:
                for(i=boundary[0];i<=boundary[2];i++)
                    ret[k++]=matrix[i][boundary[3]];
                boundary[3]--;  
                break;
            case 2:
                for(i=boundary[3];i>=boundary[1];i--)
                    ret[k++]=matrix[boundary[2]][i];
                boundary[2]--;
                break;
            case 3:
                for(i=boundary[2];i>=boundary[0];i--)
                    ret[k++]=matrix[i][boundary[1]];
                boundary[1]++;
                break;
        }    
            direction=(direction+1)%4;//更换方向
    }
    return ret;
}

```
