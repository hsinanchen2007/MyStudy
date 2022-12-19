
![image.png](https://pic.leetcode-cn.com/16fcbb510261eefd78920c71e2a15d4a4e613f6a971545d7b8d73b52aa02c350-image.png)

没什么好说的orz

```
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        #一个历史记录
        lastkeys=set()
        #n为1的时候跳出
        while n!=1:
            #计算新的n
            newkey=0
            for i in str(n):
                newkey+=int(i)**2
            n=newkey
            #如果新的n出现在历史里过，证明无限循环，跳出循环返回false
            if n in lastkeys:
                return False
            #增加历史
            lastkeys.add(n)
        #正常通过，返回true
        return True
```
