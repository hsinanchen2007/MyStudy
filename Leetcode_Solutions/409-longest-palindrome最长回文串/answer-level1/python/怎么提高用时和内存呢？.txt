### 解题思路
找出偶数个数字母的数量，组合起来的长度小于原长度则说明还有单个字母可以放在最中间

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        j=0
        for i in set(s):            
            j=j+s.count(i)//2
        return 2*j+1 if len(s)>2*j else 2*j    
            
```