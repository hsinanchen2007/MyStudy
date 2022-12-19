![image.png](https://pic.leetcode-cn.com/42f16b7dff14edb7f5707d561523142263074d8d79aa91247194070023b462d0-image.png)
![image.png](https://pic.leetcode-cn.com/82f5152804cc4b066da142b62a5bb84c8dfbbf717bce8cf5d426136d88631483-image.png)

思路：  
1. 从左到右遍历，记录当前最高的值，每次遇到大于或等于当前的最大值，就将上一个最大值放进左指针，当前最大值放进右指针，并计算此凹槽中的水。若小于最大值，则将当前值累加，用于计算每个凹槽水量时减去其中阻挡的部分。计算出上图的凹槽1，凹槽2
2. 第二个循环是从尾部开始遍历，方法同1，当遇到1中的最大值时跳出循环。计算出凹槽3
```
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        index = 1
        left = 0
        right = 0
        lindex = 0
        rindex = 0
        tmp = 0
        for i in height:
            if i >= right:
                left = right
                right = i
                lindex = rindex
                rindex = index
                ans += (rindex - lindex - 1) * left - tmp
                tmp = 0
            else:
                tmp += i            
            index += 1
        stopnum = right
        index = 1
        left = 0
        right = 0
        lindex = 0
        rindex = 0
        tmp = 0
        for i in height[::-1]:
            if i >= right:
                left = right
                right = i
                lindex = rindex
                rindex = index
                ans += (rindex - lindex - 1) * left - tmp
                tmp = 0
            else:
                tmp += i
            index += 1
            if i == stopnum:
                return ans
        return ans
```
有没有好的办法只遍历一遍？
