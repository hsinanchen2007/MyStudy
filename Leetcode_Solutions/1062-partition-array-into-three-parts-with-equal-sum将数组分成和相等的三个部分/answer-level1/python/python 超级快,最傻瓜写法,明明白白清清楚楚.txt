1.![领口png.png](https://pic.leetcode-cn.com/11c8d6bf8bce91e79db7475b804d26d28142b9d495b39de11b9976a21ebb0c76-%E9%A2%86%E5%8F%A3png.png)

2. 先求和,判断和除3是否为整数.
2. 创建一个列表,从头求每一部分的和,求出的第一部分,第二部分,添加到列表
3. 求出第二部分后, 第三部分,就是剩余数组的和了**(这个可以确保只求三个部分的和)**
4. 如果数组,第一段,第二段,第三段的值相等, return True
```
class Solution(object):
    def canThreePartsEqualSum(self, A):
        amount = sum(A)
        single = amount / 3
        if single % 1 == 0: 
            s = 0
            l = []
            for i in range(len(A)):
                s += A[i]
                if s == single:
                    l.append(s)  # 第一段求出后,加入数组,和清零
                    s = 0 
                    if len(l) == 2 and i != len(A)-1: # 求出前两部分和后,求第三部分     超出索引求和为0,我也不知道
                        c = sum(A[i+1:])
                        l.append(c)
                        return l[1] == l[0] == l[2]
        return False
```
