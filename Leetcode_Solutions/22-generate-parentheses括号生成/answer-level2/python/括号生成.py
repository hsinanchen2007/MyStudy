### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        k = ''
        result = []
        def back(k,count1,count2,result,n):
            if len(k) == 2 * n and count1 == n and count2 == n:
                result.append(k)
                return
            if count1 > n or count2 > n:
                return
            if count1 >= count2:
                tem1 = k + '('
                back(tem1,count1 + 1,count2,result,n)
                tem2 = k + ')'
                back(tem2,count1,count2 + 1,result,n)
        back(k,0,0,result,n)
        return result
```