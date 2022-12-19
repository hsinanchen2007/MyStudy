### 解题思路（无参考的弱鸡解法）
- 建立一个字典，映射字符与数值；
- 一个键表用于判断罗马数字字符是否存在
- 遍历键表，发现字符则替换位空，并在结果上加上相应的数字，直到字符为空

### 代码

```python
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000
                ,'IV':4,'IX':9,'XL':40,'XC':90,'CD':400,'CM':900}
        res = 0
        keys = ['IV','IX','XL','XC','CD','CM','I','V','X','L','C','D','M']

        for key in keys:
            if not s:
                break

            if key in s:
                n = s.count(key)
                res += dic[key]*n
                s = s.replace(key,'')
        return res
```