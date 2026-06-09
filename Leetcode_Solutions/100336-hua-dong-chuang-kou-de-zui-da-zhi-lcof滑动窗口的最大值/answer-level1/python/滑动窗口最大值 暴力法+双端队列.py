### 解题思路
此处撰写解题思路

### 代码

```
# python 方法一： 使用双端队列
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if not nums:
            return []
        result = [] # 结果集
        queue = []  # 双端队列
        for i in range(0,len(nums)): # i从头遍历到尾
            while queue and nums[queue[-1]] < nums[i]:
        #  双端队列不为空且队尾元素小于当前元素
        #  只存有可能成为最大值的数字的index进deque
                queue.pop()  # 队尾弹出
            queue.append(i)  # 当前元素加入队列
            while i-queue[0] > k-1: # 相距超过窗口k的大小废弃掉
                queue.pop(0)
            if i >= k-1:
                result.append(nums[queue[0]])
                # 过程中始终保持deque[0]为最大值的索引
        return result
````
```
# python 方法二：暴力解法
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        if not nums:  # 数组nums不存在 直接返回[]
            return []
        if k > len(nums) or k < 1:
            return []  # 如果滑动窗口大小大于数组大小或小于1，返回[]
        res = []  # 收集 结果
        i = 1
        j = k+1  # 下一轮的框
        maxa = max(nums[:k]) # 第一轮0-k的最大值
        res.append(maxa) # 第一轮加入结果集
        while j <= len(nums): # 框不大于数组长度时循环
            if maxa == nums[i-1]:
    # 挪到下一个框时，比较退出一个元素的大小，若等于，说明退出的是最大的元素
    # 在下一个框中寻找最大元素
                maxa = max(nums[i:j])  # 重新找最大值
                res.append(maxa)
            elif maxa < nums[j-1]:
        # 新进入的元素比当前最大元素大
                maxa = nums[j-1]
                res.append(maxa)
            else:
                # 当前最大值仍然是max
                res.append(maxa)
            i+=1
            j+=1
        return res
```