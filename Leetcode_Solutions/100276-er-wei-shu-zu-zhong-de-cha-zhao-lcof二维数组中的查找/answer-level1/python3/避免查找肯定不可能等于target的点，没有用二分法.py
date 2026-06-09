
避免去查找肯定不可能为目标值的坐标
比如
第k行只查到第n个元素时比target大，那个第k+1行的第n个元素及之后的元素肯定都比target大，就不要查找了
如果第一个元素就比target大，那么后面肯定找不到了
![image.png](https://pic.leetcode-cn.com/9a6b3d77d938fdb19d99c57e82ef1664c860b3a4fa82f9787c7bd051c47dc508-image.png)
```
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:       
        if len(matrix)==0 or len(matrix[0])==0: 
            return False 
        length = len(matrix[0])     
        for i in range(len(matrix)):
            j = 0
            if matrix[i][0] > target: 
                return False
            while j < length:
                if matrix[i][j] < target:
                    j+=1
                elif matrix[i][j] > target:
                    length = j
                    break
                else:
                    return True
        return False
```
