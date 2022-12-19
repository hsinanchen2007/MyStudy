### 解题思路
先沿第一列方向竖着找，定位到行再横着找

### 代码

```c
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int start, mid, end;
    int row;
    
    if(0 == matrixSize || 0 == matrixColSize[0]){
        return false;
    }
    // bin search Y direction
    //matrix[a~b][0];
    start = 0;
    end = matrixSize-1;

    while(start<=end){
        mid = (start+end)/2;
        if(matrix[mid][0] == target) return true;
        else if(matrix[mid][0]<target) start = mid+1;
        else end = mid-1;
    }
    if(end<0) return false;

    row = end;
    // bin search X direction
    //matrix[row][a~b]
    start=0;
    end = matrixColSize[row]-1;
    while(start<=end){
        mid = (start+end)/2;
        if(matrix[row][mid] == target) return true;
        else if(matrix[row][mid] < target) start = mid+1;
        else end = mid-1;
    }

    return false;

}
```