# 先上图
![TIM截图20200404004444.jpg](https://pic.leetcode-cn.com/6a5dbcea804015bd40d74aa6285e786d03797cf4e3a70d21cc89dbed3c043888-TIM%E6%88%AA%E5%9B%BE20200404004444.jpg)
# 思想：
先从头往后，双指针i=0,j=i+1，定义一个sub_sum用来计算应该被减去的总和，定义res=0作为最终结果。
i和j均小于列表长度时：
当height[j] < height[i]时：
```
sub_sum += height[j]
j += 1
```
当height[j] >= height[i]时：
```
res += ((j-i-1)*height[i] - sub_sum)
i = j
j = i+1
sub_sum = 0
```
走完以上步骤，此时列表里的第i个元素应该是整个列表最大的值，若height[i]不是最后一个元素，那它后面还有可能存在雨水的情况，因此，将后半部分逆转，再重复刚才的步骤。
```
height = height[i:]
height.reverse()
```
完整代码，写的有点长，核心就一块，简单易懂：
```
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        i = 0
        j = 1
        sub_sum = 0
        res = 0
        while i < n and j < n:
            if height[j] < height[i]:
                sub_sum += height[j]
                j += 1
            elif height[j] >= height[i]:
                res += ((j-i-1)*height[i] - sub_sum)
                i = j
                j = i+1
                sub_sum = 0
        height = height[i:]
        height.reverse()
        n = len(height)
        i = 0
        j = 1
        sub_sum = 0
        while i < n and j < n:
            if height[j] < height[i]:
                sub_sum += height[j]
                j += 1
            elif height[j] >= height[i]:
                res += ((j - i - 1) * height[i] - sub_sum)
                i = j
                j = i + 1
                sub_sum = 0
        return res
```
