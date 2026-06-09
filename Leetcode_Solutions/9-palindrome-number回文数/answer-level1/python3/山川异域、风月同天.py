### 解题思路
这个题目不是很难，搞懂了第7题，这个题目也就懂了。但是进阶的部分没有做出来
### 代码

```python3
class Solution:
    def isPalindrome(self, x):
        if x < 0:
            return False
        else:
            y = str(x)
            y = int(y[::-1])
            if x == y:
                return True
            else:
                return False
```