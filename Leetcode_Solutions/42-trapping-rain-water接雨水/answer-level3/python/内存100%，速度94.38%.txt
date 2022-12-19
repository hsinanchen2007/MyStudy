算法就不详细写了，很多大佬已经分析的很好了。
1.左右指针往最高柱靠。
2.左高柱和右高柱低者决定左右指针谁运动和当前左或右水位。
3.左指针移动但是当前柱不高于左高柱时，新增水量为两者高度差，右指针类比之。
内存占有小的原因大概是除指针外只定义了左高柱和右高柱两个变量。
附上代码：
```
class Solution(object):
    def trap(self, height):
        if len(height)<3:
            return 0
        l = 0
        r = len(height)-1
        lhigh = height[0]
        rhigh = height[len(height)-1]
        res = 0
        while l<=r:
            if lhigh<=rhigh:
                if height[l]>lhigh:
                    lhigh = height[l]
                else:
                    res += lhigh - height[l]
                l+=1
            else:
                if height[r]>rhigh:
                    rhigh = height[r]
                else:
                    res += rhigh - height[r]
                r-=1
        return res
```
