### 解题思路
大佬们是真的强666666
return len(astr) == len(set(astr))
这样不就直接返回布尔值了嘛  qwq
我人没了hhh
一开始用的是count，没想到啊，判断是否重复，直接使用set就可了……orz，也没想到return加上判断直接就可以等于布尔值OAO
我是垃圾

### 代码

```python3
class Solution:
    def isUnique(self, astr: str) -> bool:
        return True if len(set(astr))==len(astr) else False

```
```python3
class Solution:
    def isUnique(self, astr: str) -> bool:
        for i in astr:
            a = astr.count(i)
            if a != 1:
        	    return False
        return True
```