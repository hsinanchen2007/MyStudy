### 解题思路
![image.png](https://pic.leetcode-cn.com/987f25fd12902a148919e247b8243942a3b50fadcea41eff74a1742a730ecf35-image.png)
回溯，找到首字母的位置，向上下左右查找，已经查过的路劲记录下来避免重复

### 代码

```python3
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])

        def search(i,j,word):
            if board[i][j] != word[0]:
                return False
            if len(word) == 1 and board[i][j] == word[0]:
                return True
            used.add((i,j))
            match = False
            # 上
            if i > 0 and (i-1,j) not in used:
                match = search(i-1,j,word[1:])
            # 下
            if not match and i < m-1 and (i+1,j) not in used:
                match = search(i+1,j,word[1:])
            # 左
            if not match and j > 0 and (i,j-1) not in used:
                match = search(i,j-1,word[1:])
            # 右
            if not match and j < n-1 and (i,j+1) not in used:
                match = search(i,j+1,word[1:])
            
            used.remove((i,j))
            return match
            pass

        for i in range(m):
            for j in range(n):                
                used = set()
                if search(i,j,word):
                    return True
        return False
```