### 解题思路
遍历字符串，符合常规，查询字典累加；你符合常规，按两位查询特殊字典累加

### 代码

```python
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        mydict={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        mydict1={'IV':4,'IX':9,'XL':40,'XC':90,'CD':400,'CM':900}
        result=0
        i=0
        while i <len(s):
            if i+1<len(s):
               if mydict[s[i]]>=mydict[s[i+1]]:
                   result+=mydict[s[i]]
               else:
                   key=s[i]+s[i+1]
                   result+=mydict1[key]
                   i=i+1
            else:
                result+=mydict[s[i]]
            i=i+1
        return result
```