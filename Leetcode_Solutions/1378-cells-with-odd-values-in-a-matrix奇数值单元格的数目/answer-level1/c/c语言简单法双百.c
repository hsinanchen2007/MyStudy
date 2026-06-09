### 解题思路
容易理解的

### 代码

```c
int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize){
    int arr[n][m];
    *indicesColSize=2;
    int i,j,count=0;
    for(i=0;i<n;i++){//数组初始化
        for(j=0;j<m;j++){
            arr[i][j]=0;
        }
    }
    for(i=0;i<indicesSize;i++){//横向加1
        for(j=0;j<m;j++){
            arr[indices[i][0]][j]++;
        }    
    }
    for(i=0;i<indicesSize;i++){//纵向加1
        for(j=0;j<n;j++){
            arr[j][indices[i][1]]++;
        }    
    }
    for(i=0;i<n;i++){//遍历奇数
        for(j=0;j<m;j++){
            if(arr[i][j]%2==1)count++;
        }
    }   
    return count;
}
```