### 解题思路
n=1,num=10**1-1,list1=[0:num]

### 代码

```python
class Solution(object):
    def printNumbers(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        if n<=0:
            return "n∈N+，retry!"
        else:
            num=10**n-1
            i=0
            list1=[]
            while(i<num):
                i+=1
                list1.append(i)
            return list1

```