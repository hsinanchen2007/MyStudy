### 解题思路
末尾添加字符是为了满足当扫描走到最后仍没有出现字符不同的情况

### 代码

```python
class Solution(object):
    def largeGroupPositions(self, S):
      S = S + '*'
      result = []
      i = 0
      j = 1
      while i <= len(S) - 4 and j < len(S):
        if S[i] == S[j]:
          j += 1
        else:
          cur_l = j - i 
          if cur_l >= 3:
            result.append([i,j-1]) 
          i = j
          j += 1
      return result
```