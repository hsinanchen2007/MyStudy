### 解题思路
![捕获.JPG](https://pic.leetcode-cn.com/9cfcb7e8ee9875e1c24b564d517fe34f86a34ab0f92f7f4c753cb6a5a599f58c-%E6%8D%95%E8%8E%B7.JPG)


方法总体利用了双指针的思路。
能接雨水的先决条件是有两列比中间地段高的墙壁，因此可以转化为一种找墙壁的过程。
首先两个指针分别在数列两端，接着确定指针移动方向。由于雨水承接的多寡由低墙确定，即水面与低墙保持水平，因此计算水量需要从低墙部分开始向高墙一侧移动，且移动中可以直接计算水深，即循环过程的第一次比较过程。
随后在低墙一侧，由于另一侧指针有高墙，即低洼处一定有水，因此对于比低墙低的直接计算其与低墙的高度差即为水量，直到遇到更高的墙，这时需要重新进行移动方向判定，进而继续计算水量，直至两指针相遇。


### 代码

```python
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        res=0
        i = 0
        hl = 0
        hr = 0
        j = len(height)-1
        while i != j and j>=0:
            if height[i]<height[j]:
                if hl<height[i]:
                    hl = height[i]
                    i = i+1
                else:
                    res = res+hl-height[i]
                    i = i+1
            else:
                if hr<height[j]:
                    hr = height[j]
                    j = j-1
                else:
                    res = res+hr - height[j]
                    j = j-1
        return res


```