```
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int Row = matrixSize;
    int Col = * matrixColSize;
    
    if(matrixSize == 0 || *matrixColSize == 0) {
        return false;
    }
   
    long left = 0;
    long right = Row * Col - 1;
    long mid,element;
    
    while(left <= right) {
        mid = (left + right) >> 1;
        element = matrix[mid / Col][mid % Col];
        
        if(element == target) {
            return true;
        } else if(element < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}
```
