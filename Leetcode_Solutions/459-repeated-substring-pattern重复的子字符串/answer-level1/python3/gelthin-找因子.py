### 解题思路
因子变量范围没控制好，接连两次提交都错误。
for i in raneg(1,n+1) 对 "aba" 出错
for i in range(2, n): 对 "bb" 出错


### 代码

```python3
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        for i in range(1, n):  #  因子长度至少为 1， 小于 n
            if n%i==0:  # 找到一个 >1 的因子
                j = 0
                while j+i <= n:
                    if s[j:j+i] != s[0:i]:
                        break
                    j += i
                if j == n:
                    return True
        return False

```