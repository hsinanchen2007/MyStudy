### 解题思路
从鞍点开始搜索

### 代码

```java []
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // 设计时间复杂度为O(N+M)
        // 从鞍点开始搜索
        int R = matrix.length;
        if(R == 0)
            return false;
        int C = matrix[0].length;
        if(C == 0)
            return false;

        int Px = R-1, Py = 0;
        while(Px >=0 && Py<=C-1){
            if(matrix[Px][Py] < target)
                ++Py;
            else if(matrix[Px][Py] > target)
                --Px;
            else
                return true;
        }
        return false; 
    }
}
```
```python []
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        R = len(matrix)
        if R == 0:
            return False
        C = len(matrix[0])
        if C==0:
            return False

        Px, Py = R-1, 0
        while Px >= 0 and Py <= C-1:
            if matrix[Px][Py] < target:
                Py+=1
            elif matrix[Px][Py] > target:
                Px-=1
            else:
                return True

        return False
```
```c++ []
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 选择鞍点出发进行搜索
        // 时间复杂度O(M+N)
        int R = matrix.size();
        if(R == 0)
            return 0;
        int C = matrix[0].size();
        if(C == 0)
            return 0;

        // 从右上角鞍点出发
        int Px = 0, Py = C-1;
        while(Px <=R-1 && Py>=0){
            if(matrix[Px][Py] > target)
                Py--;
            else if(matrix[Px][Py] < target)
                Px++;
            else{
                return true;
            }
        }

        return false;
    }
};
```