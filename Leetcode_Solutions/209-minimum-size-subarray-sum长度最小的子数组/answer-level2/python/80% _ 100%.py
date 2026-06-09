### 解题思路
滑动窗口，如果窗口内的和超过s，就左移左边界，否则右移右边界

### 代码

```python3
class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        left = 0        # 左指针
        right = 0       # 右指针
        MAX = 0XFFFFFFFF# 窗口最大长度
        minSize = MAX   # 所求的结果
        curSize = 0     # 当前窗口长度
        curSum = 0      # 窗口内的数字和
        while right <= len(nums): # 这个要等号，比较特殊，和下文有关
            # print('curSum', curSum, left, right)
            if curSum >= s:       # 窗口内和超过 s
                if curSize < minSize:
                    minSize = curSize   # 更新最小窗口
                curSum -= nums[left]    # 准备右移左边界，先减去和
                left += 1               # 右移左边界
                curSize -= 1            # 窗口大小 -1
                
            else:                       # 窗口内和 <s
                if right != len(nums):  # 防止超范围，同时保证nums中最后一个数能加上，做的时候这里卡了很久，因为是先把 nums[right] 加上再更新right的，这里和前面的  while 循环等号有关
                    curSum += nums[right]
                right += 1              # 窗口有边界右移
                curSize += 1            # 窗口增大
        res = minSize if minSize != MAX else 0      # 没有符合条件的就返回0
        return res
```