### 解题思路
![image.png](https://pic.leetcode-cn.com/c6fd1da8b30727dc4c2c8128c7ef00a6cb7a95b60b15c924e341778f9e5136a6-image.png)


和第一道题一样一样的
### 代码

```c
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
     if(n==0){
        *returnSize = 0;
        ** returnColumnSizes = 0;
        return;
    }

    // initialization
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    int **matrix = (int **)calloc(n,sizeof(int *));
    for(int i=0; i<n; i++){
        matrix[i] = (int *)calloc(n,sizeof(int));
        matrix[i][0] = 0;
        (*returnColumnSizes)[i] = n;
    }

    int cnt=1;
    int direction = 1;//1--right, 2--down, 3--left, 4-up
    int i=0,j=0;

    while(cnt<=n*n){
        if(direction==1){//go right
            while(j<n && matrix[i][j]==0){
                matrix[i][j] = cnt++;
                j++;
            }
            j--, i++;
            direction=2;
        }else if(direction==2){//go down
            while(i<n && matrix[i][j]==0){
                matrix[i][j] = cnt++;
                i++;
            }
            i--, j--;
            direction=3;            
        }else if(direction==3){//go left
            while(j>=0 && matrix[i][j]==0){
                matrix[i][j] = cnt++;
                j--;
            }
            j++, i--;
            direction=4; 
        }else if(direction==4){//go up
            while(i>=0 && matrix[i][j]==0){
                matrix[i][j] = cnt++;
                i--;
            }
            i++, j++;
            direction=1; 
        }
    }
    return matrix;
}
```