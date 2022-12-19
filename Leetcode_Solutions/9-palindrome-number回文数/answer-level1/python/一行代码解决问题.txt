### 解题思路
此处撰写解题思路
1. 形成字符串并反转
2. 中位数为界限，X前面一半数字等于反转后前一半数字
### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
            return True if str(x)[0:len(str(x))//2] == str(x)[::-1][0:len(str(x))//2] else False

```