### 解题思路
![QQ截图20200324164112.png](https://pic.leetcode-cn.com/c75319f85f3b3cc221768a57621da7fd8f21766e0a8b40c4f872d2e647f18cdd-QQ%E6%88%AA%E5%9B%BE20200324164112.png)

即198.打家劫舍问题，换个语言，把今天的打卡题水过去

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        if len(nums)==1:
            return nums[0]
        dp_max=[]
        dp_max.append(nums[0])
        dp_max.append(max(nums[0],nums[1]))
        for i,n in zip(range(2,len(nums)),nums[2:]):
            dp_max.append(max(n+dp_max[i-2],dp_max[i-1]))
        return dp_max[len(nums)-1]
```