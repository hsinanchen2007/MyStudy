### 方法一
基本思路就是在暴力解题的过程中加入一些判断条件:
1. 条件一: 假设当前滑动窗口的最大值为 x ,当进行滑动时会有一个一个元素进入,一个元素退出,首先比较退出的元素是否为最大的元素,如果是的话,则需要重新找到新窗口的最大值
2. 条件二: 如果进入的元素 p 比当前最大的 x 大,则直接将 p 加入到结果中
3. 如果上述两个条件都不满足,则当前的最大值还是 x ,加入到结果中即可
![image.png](https://pic.leetcode-cn.com/739a8388914490c95c00cc1a558aa3eb8167a90497bab6dfdcf78fbfe4b86486-image.png)

### 代码

```python
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if not nums :
            return []
        result = []
        i = 1
        j = k + 1
        max_ = max(nums[:k])
        result.append(max_)
        while j <= len(nums):
            if max_ == nums[i-1]:
                max_ = max(nums[i:j])
                result.append(max_)
            elif max_ < nums[j-1]:
                max_ = nums[j-1]
                result.append(max_)
            else:
                result.append(max_)
            i += 1
            j += 1
        return result


                
            
            
```



### 方法二:使用双端队列进行求解
![image.png](https://pic.leetcode-cn.com/0a38c77f19e55083250e33ca2ca42aefc4f038f1178cef3800f8c8c762dbdb37-image.png)
- 假设给定一组数: [1,3,-1,-3,5,3,6,7] 和 k = 3
- 我们设置一个双端的队列只用来存储最大的元素的下标
- 下面分析下步骤:(下面以 k-m 的形式代表下标恩对应的数值,k为下标,m为数值)
- 1.开始时我们的队列进入 0-1 ,将下标0存入队列, 接着进入 1-3,此时 3 > 1,我们就会把下标 0 删除掉,将下标 1 存入队列, 继续进入 2-(-1) ,
- 直接放入队列里面,这个数值可能是下一个滑动窗口的最大值,继续这样遍历下去.
- 当队列中出现的下标的不在当前的滑动窗口内是后,我们直接将这个下标移出掉
- 我们想要的结果就保存在队头元素里面

```
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        from collections import deque
        if not nums :
            return []
        result = []
        deque_ = []
        for i in range(len(nums)):
            while deque_ and nums[deque_[-1]] < nums[i]:
                deque_.pop()
            deque_.append(i)
            if deque_[0] == (i - k):
                deque_.pop(0)
            if i >= k-1:
                result.append(nums[deque_[0]])
        return result
```
