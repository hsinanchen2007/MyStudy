### 解题思路
统计字母数量，小心奇数个字母即可
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        co = collections.Counter(s)
        count = 0
        flag = False
        for i in co.values():
            count += i//2
            if i%2==1:
                flag = True
        if flag:
            return count*2+1
        else:
            return count*2

```