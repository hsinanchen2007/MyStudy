理由：
题干说每行递增且每列递增，如果直接将二维数组通过下标整除和取余转化为一维数组，
然后整体二分查找只能过大部分用例，要通过全部用例，踏实地逐行二分查找就好
```
bool searchMatrix(int** matrix, int matrixSize, int matrixColSize, int target){
    int row = matrixSize;
    int col = matrixColSize;
    for(int i = 0 ; i < row; i++){
        int low = 0;
        int high = col - 1;
        int mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(target == matrix[i][mid]){
                return true;
            } else if(target > matrix[i][mid]){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false;
}
```

