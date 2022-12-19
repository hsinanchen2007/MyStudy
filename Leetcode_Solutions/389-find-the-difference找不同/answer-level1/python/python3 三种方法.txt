
方法一
排序后，比较两个字符串的每一位，有不同的即答案。因为有做sort,所以时间是nlogn
```
def findTheDifference( s, t) :
    if not s:
        return t
    s = sorted(list(s))
    t = sorted(list(t))
    for i in range(len(s)):
        if t[i] != s[i]:
            return t[i]
    return t[i+1]
```

方法二
用set存储，可以在o(1)时间查到是否出现过，然后去重，时间是o(n)，不过需要o(n)的内存

```
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        res=set()
        for i in s+t:
            if i in res:
                res.remove(i)
            else:
                res.add(i)
        return res.pop()
```


方法三 
异或

思路同136一样，只不过多了个ascii转换。因为一遍，所以时间是o(n)
解释下，
1， 0和数字异或为该数字本身
2， 相同数字异或为0
3， 异或满足交换律，即可以把相隔很远的相同数字移到隔壁。

```
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        res=0
        for i in s+t:
            res^=ord(i)
        return chr(res)
```
