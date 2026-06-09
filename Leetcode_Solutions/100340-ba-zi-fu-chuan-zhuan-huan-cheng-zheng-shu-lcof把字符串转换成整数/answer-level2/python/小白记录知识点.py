### 解题思路
此处撰写解题思路
正则表达式，re.compile()，^表示匹配字符串首，?匹配前面字符0或1次，\d表示0-9，+表示1+次。
str.strip()表示去掉字符串两侧的空格。
### 代码

```python3
class Solution:
    def strToInt(self, str: str) -> int:
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        s= str.strip()#去掉字符串前面和后面的空格.
        res=re.compile(r'^[\+\-]?\d+')
        nums=res.findall(s)
        if nums:
            num = int(nums[0])
        else:
            return 0
        if num>2**31-1:
            return 2**31-1
        elif num<-2**31:
            return -2**31
        else:
            return num
```