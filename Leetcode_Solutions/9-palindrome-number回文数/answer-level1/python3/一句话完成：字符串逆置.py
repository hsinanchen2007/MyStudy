### 解题思路
此处撰写解题思路
1.字符串逆置
2.对比

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        return str(x)[::-1] == str(x) 
```