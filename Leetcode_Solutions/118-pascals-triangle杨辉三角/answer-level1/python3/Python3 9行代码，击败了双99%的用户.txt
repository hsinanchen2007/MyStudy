### 解题思路
利用动态规划的思想，第i个数组的元素是第i-1个数组连续相连两个元素之和。
![image.png](https://pic.leetcode-cn.com/52c71c9cfddec98a6a060b96f6a0a45a515c89248824c82606fac02d52586628-image.png)

### 代码

```python3
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if not numRows:
            return []
        res = [[1]]
        for i in range(numRows-1):
            tmp = [1] # 第0位先置1
            nums = res[i]
            for j in range(len(nums)-1): # 注意这里是i-1 ,取不到第i个数
                tmp.append(nums[j] + nums[j+1])
            res.append(tmp+[1]) # 最后一位也要记得置1
        return res
```
欢迎关注的我的[github](https://github.com/tcandzq/LeetCode)，查看更多精彩题解