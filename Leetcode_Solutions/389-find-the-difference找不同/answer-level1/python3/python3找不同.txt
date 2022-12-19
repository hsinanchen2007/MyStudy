异或运算找出多余的元素
```
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        res=0
        for i in s:
            res^=ord(i)
        for j in t:
            res^=ord(j)
        return chr(res)
```
![image.png](https://pic.leetcode-cn.com/5166cb21deebe015b7c0debdbc30e739931390ac3ec80e6a9dcc6cdcf3ce56ba-image.png)
