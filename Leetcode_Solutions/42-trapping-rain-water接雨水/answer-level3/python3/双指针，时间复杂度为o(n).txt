### 解题思路
解决这个问题只需要将大问题看为分步的小问题。
i，j分别为左右指针，t为临界点。
从左向右遍历，当height[t]>=height[i] 时找到一个可以接雨水的坑：
![1.jpg](https://pic.leetcode-cn.com/2550d3108c5660f2c2fc82831bbc5a5904277c06055bd5b38e0b8a6dca9abd05-1.jpg)
如果找不到坑，则再从右向左遍历。
直到i>=j为止


### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        i,j = 0,len(height)-1
        nums = 0
        while i<j:
            t = i+1
            num = 0
            while t<=j and height[i]>height[t]:
                num += (height[i]-height[t])
                t += 1
            if t<=j:
                nums += num
                i = t
            else:
                t = j-1
                num = 0
                while t>=i and height[j]>height[t]:
                    num += (height[j]-height[t])
                    t -= 1
                if t>=i:
                    nums += num
                    j = t


        return nums
                    

            





```