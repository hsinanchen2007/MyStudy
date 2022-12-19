### 解题思路
很简单 一次遍历，过程中遇到连续三个0，则可种一颗 
处理边界问题上，可在数组首尾增加一个零，以此规避首尾001 和 100这种零不够但可以种花的情况 代码如下

### 代码

```python
class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        num=0
        flowerbed.insert(0,0)
        flowerbed.append(0)
        for i in range(len(flowerbed)):
            if flowerbed[i]==0:
                num+=1
            else:
                num=0
            if num ==3 :
                n-=1
                num=1
        
        return n<=0
```