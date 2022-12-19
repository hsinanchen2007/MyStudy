### 递归+记忆化搜索

```python
class Solution:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        '''
        递归+记忆化搜索
        '''
        p1 = len(s1) - 1
        p2 = len(s2) - 1
  
        table = {}  # 记录已对比过的字符的下标，值为对比此字符时最大的公共子串长度
        # 也可以用二维数组记录（如动态规划法的解）

        def parse(s1, s2, p1, p2):
            if p1 < 0 or p2 < 0:
                return 0
            elif (p1, p2) in table:
                return table[(p1, p2)]

            if s1[p1] == s2[p2]:
                res = 1 + parse(s1, s2, p1 - 1, p2 - 1)
            else:
                res = max(parse(s1, s2, p1 - 1, p2), parse(s1, s2, p1, p2 - 1))

            table[(p1, p2)] = res

            return res

        return parse(s1, s2, p1, p2)
```

### 动态规划

```python
class Solution:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        '''
        动态规划
        '''
        l1 = len(s1)
        l2 = len(s2)
        
        # 代表在对比下标为s1中下标为i的字符，和s2中下标为j的字符时，最长子序列的长度
        table = [[0 for _ in range(l2+1)] for _ in range(l1+1)]
        
        for i in range(l1):
            for j in range(l2):
                if s1[i] == s2[j]:
                    table[i+1][j+1] = 1 + table[i][j]
                else:
                    table[i+1][j+1] = max(table[i][j+1], table[i+1][j])
        
        return table[-1][-1]
```
