
解空间树框架如下图所示

![image.png](https://pic.leetcode-cn.com/1491f93a418df19d85c31d2d3614727dbbdd0b798f764d64150aac6516dd221c-image.png)

对于一个数组来说，寻找解得过程如下图所示，节点为当前连续子序列的和，如果发生遗忘，则子序列和发生下降，，则忘记前面连续的自序和，重新累加。

![image.png](https://pic.leetcode-cn.com/6f758e6838ca422dc6eb8aa5d90de80913bf3e64a24ac30a515ac60a63c7ecad-image.png)

```
class Solution(object):

    def __init__(self):
        self.max_sum=float('-inf')
        self.nums=None

    def dfs(self,tmp_sum,i):
        if i<len(self.nums):
            # select or forget
            self.max_sum=max(self.max_sum,max(tmp_sum+self.nums[i],self.nums[i]))
            self.dfs(tmp_sum+self.nums[i],i+1) if tmp_sum+self.nums[i]>self.nums[i] else self.dfs(self.nums[i],i+1)
                
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        self.nums=nums
        self.dfs(0,0)
        return self.max_sum
        
```
