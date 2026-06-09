### 使用额外空间(dp)
![image.png](https://pic.leetcode-cn.com/64d8e36fbccf4dea661da40520834e914d59b4f0e3ec564a8d8ab537581d1382-image.png)
- 我们可以创建一个数组,里面是排好序的丑数,每一个丑数都是前面的丑数乘以2,3,5得到的
- 假设我们数组中已经有排好序的丑数,并且我们把最大的丑数即为`M`,我们接下来需要做的是如何确定下一个丑数
- 我们首先考虑把所有已有的丑数分别乘以2,3,5.然后取他们这些乘积中大于`M`的最小值,那些成绩比`M`小的我们不需要考虑,这就是我们要找的下一个丑数
- 那我们该怎么实现呢:
- 设置三个指针:`dp2`,`dp3`,`dp5`,这三个指针分别代表已有的丑数成2或者3或者5,比如`dp3`所指向的丑数就只乘以3
- 但是我们还要想下不能每次都从头带领着三个指针分别做乘法,这样的复杂度很高的
- 因为在数组中的丑数是有序的,对于乘以2的丑数而言,肯定存在某一个丑数`T2`,排在他前面的每个丑数乘以2得到的结果都会小于已有的最大丑数`M`,在他之后的每个丑数乘以2得到的结果都会太大
- 所以我们只需要记录下这个丑数的位置,每次有了新丑数更新一下就可以了
- 下面的代码中有注释掉的while循环的解法,其实是一样的,理解起来更好理解点
### 代码

```python
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = 1
        temp = 1
        dp2, dp3, dp5 = 0,0,0
        result = [1]*n
        while temp < n:
            result[temp] = min(result[dp2]*2, result[dp3]*3, result[dp5]*5)
            # while result[dp2]*2 <= result[temp]:
            #     dp2 += 1
            # while result[dp3]*3 <= result[temp]:
            #     dp3 += 1          
            # while result[dp5]*5 <= result[temp]:
            #     dp5 += 1
            if result[dp2]*2 == result[temp]:
                dp2 += 1
            if result[dp3]*3 == result[temp]:
                dp3 += 1
            if result[dp5]*5 == result[temp]:
                dp5 += 1
            temp += 1
        return result[temp-1]


```