### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        if len(flowerbed)==1 and 1 not in flowerbed:
            return n<=1
        elif len(flowerbed)==2 and 1 not in flowerbed:
            return n<=1
        res=0
        p=0
        flowerbed.insert(0,0)
        flowerbed.append(0)
        while p<=len(flowerbed)-3:
            if 1 not in flowerbed[p:p+3]:
                res+=1
                p+=2
            else:
                p+=1
        return res>=n
```