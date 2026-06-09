### 解题思路
以每行的末尾元素作为pivot

### 代码

```java []
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int R = matrix.length;
        if(R == 0)
            return false;
        int C = matrix[0].length;
        if(C == 0)
            return false;

        int i = 0;
        while(i<R){
            if(matrix[i][C-1] < target)
                ++i;
            else if(matrix[i][C-1] > target){
                for(int j=C-1; j>=0; --j){
                    if(matrix[i][j] == target)
                        return true;
                }
                return false;
            }
            else{
                return true;
            }
        }
        return false;
    }
}
```
```python []
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        R = len(matrix)
        if R==0:
            return False

        C = len(matrix[0])
        if C == 0:
            return False

        i = 0
        while i<R:
            if matrix[i][C-1] < target:
                i+=1
            elif matrix[i][C-1] > target:
                for j in range(C-1, -1, -1):
                    if matrix[i][j] == target:
                        return True
                return False
            else:
                return True

        return False
```
```c++ []
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 从每行的首元尾进行定位
        int R = matrix.size();
        if(R == 0)
            return false;
        int C = matrix[0].size();
        if(C == 0)
            return false;

        int i=0;
        while(i<R){
            if(matrix[i][C-1] < target){
                ++i;
            }
            else if(matrix[i][C-1] > target){
                for(int j=C-2; j>=0; --j)
                    if(matrix[i][j] == target)
                        return true;
                return false;
            }else{
                return true;
            }
        }

        return false;
    }
};
```