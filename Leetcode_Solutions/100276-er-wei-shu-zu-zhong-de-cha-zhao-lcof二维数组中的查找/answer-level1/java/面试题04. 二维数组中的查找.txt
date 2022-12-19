#### 右上角法：

```java []
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix.length == 0){
            return false;
        }
        int rows = matrix.length;
        int columns = matrix[0].length;
        int i = 0;
        int j = columns - 1;
        int item;
        while(i < rows && j >= 0){
            item = matrix[i][j];
            if(item == target){
                return true;
            }else if(item < target){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
}
```
```python []
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix:
            return False
        rows = len(matrix)
        columns = len(matrix[0])
        i = 0
        j = columns - 1
        while i < rows and j >= 0:
            item = matrix[i][j]
            if item == target:
                return True
            elif item < target:
                i = i + 1
            else:
                j = j - 1
        return False
```
