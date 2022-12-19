### 解题思路
使用两个推导式，注意reverse函数不返回任何值，list是可变的对象

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        news=[x.lower() for x in s if x.isalnum()]
        return news==[news[len(news)-i-1] for i in range(0,len(news))]
```