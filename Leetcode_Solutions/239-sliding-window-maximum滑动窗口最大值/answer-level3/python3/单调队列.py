### 解题思路
1. 解题目标：
- 窗口每滑动一步时，记录窗口元素中的最大值
2. 解题思路：
- 单调队列
- 先自建一个单调队列
- 将k个元素push到mq，输出mq的最大值
- 向前滑动一步，滑动掉的值为a，mq删除a，，输出mq的最大值
- 重复

### 代码

```python3

class Max_queue():
    def __init__(self):
        #递减的队列
        self.q = []
    #每次push的时候，把队列中，小于当前元素的值删除
    def push(self,val):
        while self.q and self.q[len(self.q)-1] < val:
            self.q.pop()
        self.q.append(val)
    #弹出首元素时，只需要判断是否为最大的元素
    def pop(self,val):
        if self.q and self.q[0] == val:
            self.q.pop(0)
    def max(self):
        return self.q[0] if self.q else -1

'''
解题目标：窗口每滑动一步时，记录窗口元素中的最大值
解题思路：
单调队列
先自建一个单调队列
将k个元素push到mq，输出mq的最大值
向前滑动一步，滑动掉的值为a，mq删除a，，输出mq的最大值
重复
'''
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        mq = Max_queue()
        res = []
        for i in range(len(nums)):
            #前k个元素
            if i < k-1:
                mq.push(nums[i])
            #向后滑动
            else:
                mq.push(nums[i])
                res.append(mq.max())
                #删除滑出滑窗的元素，[1,2,3,4]:[1,2,3]->[2,3,4]，mq中要删除1
                mq.pop(nums[i-(k-1)])
        return res









```