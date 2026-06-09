# 每一次记录所有位数的平方和存入列表中 如果有重复说明陷入无限循环 即不是快乐数
```
class Solution(object):
    def isHappy(self,n):
        """
        :type n :int
        :rtype : bool
        """
        if n==0:
             return False
        list1=[]
        while n!=1:
            n_1=str(n)
            l=len(n_1)
            count=0
            for i in range(l):
                count+=int(n_1[i])**2
            if count in list1:
                return False
            else:
                list1.append(count)
            n=count
```
# 不快乐数会进入4-16-37-58-89-145-42-20-4的循环中
```
class Solution(object):
    def isHappy(self,n):
        """
        :type n :int
        :rtype : bool
        """
        if n==0:
            return False
        while n!=1:
            n_1=str(n)
            l=len(n_1)
            count=0
            for i in range(l):
                count+=int(n_1[i])**2
            if count in [4,16,37,58,89,145,42,20,4]:
                return False
            n=count
        return True
```
求各位数的平方和也可以用
```
while n:
                count=(n%10)**2
                n=n//10
```