### 解题思路
首先把大写字母转换成小写字母，把出现的字母和数字存下来，然后前后对比。空间复杂度比较高。

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        string = []
        for i in s:
            i = i.lower()
            if i.isalnum():
                string.append(i)
        return string == string[::-1]

```