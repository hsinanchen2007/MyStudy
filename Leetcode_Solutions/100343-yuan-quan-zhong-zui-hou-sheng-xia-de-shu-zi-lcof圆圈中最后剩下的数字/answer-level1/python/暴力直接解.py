### 解题思路
暴力解法，根据题目意思直接解，根据题目每一次都会删掉一个元素，所以最后剩下的那个元素就是答案。
以[0,1,2,3,4]为例：删除m=3
第一轮删除索引为  (0+2)%len(上次的长度) = 2       剩下[0,1,3,4]
第二轮删除索引为  (2+2)%len(上次的长度) = 0       剩下[1,3,4]
第三轮删除索引为  (0+2)%len(上次的长度) = 2       剩下[1,3]
第四轮删除索引为  (0+2)%len(上次的长度) = 0       剩下[3]
得出答案
至于为什么只加上m-1，是因为当你删除当前元素的时候，你的下一个元素就变成第一个元素了，所以需要少加一次。



### 代码

```python
class Solution(object):
    def lastRemaining(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        if n==0:
            return 0
        temp=list(range(n))
        num=0
        m=m-1
        while len(temp) > 1:
            num+=m
            num%=len(temp)
            temp.pop(num)
        return temp[0]       
```