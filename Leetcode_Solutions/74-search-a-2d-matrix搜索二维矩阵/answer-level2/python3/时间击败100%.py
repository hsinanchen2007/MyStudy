![屏幕快照 2020-01-14 下午9.20.13.png](https://pic.leetcode-cn.com/cda6a8d94ea23a56429c8a12a9b29b36c910bd7b74ec08f48767f734589aedf8-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-14%20%E4%B8%8B%E5%8D%889.20.13.png)

### 解题思路
此处撰写解题思路
先处理头尾，
然后就看每行第一位即可

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        size = len(matrix)
        if(size == 0): return False
        if(target in matrix[0] or target in matrix[size-1]) : return True
        else:
            for i in range(1,size):
                if(matrix[i][0]==target): return True
                elif(matrix[i][0]>target): return target in matrix[i-1]
                else: continue
            return False

```