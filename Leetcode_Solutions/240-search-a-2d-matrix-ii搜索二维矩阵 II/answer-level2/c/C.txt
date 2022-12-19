### 解题思路

从左下角开始找起 复杂度 O(matrixRowSize + matrixColSize)

### 代码

```c
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i = 0;
    int j = matrixRowSize - 1;
    while(j >= 0 && i < matrixColSize){       
        if(matrix[j][i] == target){
            return true;
        }
        else if(matrix[j][i] < target){
            ++ i;            
        }
        else{
            -- j;
        }
    }
    return false;
}
        
```