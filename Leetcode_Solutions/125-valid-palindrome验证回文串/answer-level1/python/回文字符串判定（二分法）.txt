采用双指针法进行求解：
  先处理字符串，将其转变为全小写，然后取出数字和字母到新的字符串，最后运用双指针中的二分法进行求解。

### 代码

```python
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s=s.lower()
        numbers = '1234567890'
        letters ='qwertyuiopasdfghjklzxcvbnm'
        y=''
        shuchu=True
        for x in s:
            if (x in numbers) or (x in letters):
                y+=x
        half = int((len(y)-1) / 2)
        if y == "":
            return True
        for i in range(0,half+1):
            if y[i] != y[len(y)-1-i]:
                shuchu = False
        return shuchu
```