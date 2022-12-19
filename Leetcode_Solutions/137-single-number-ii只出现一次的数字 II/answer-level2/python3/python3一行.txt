### 解题思路
简单的数学问题
![UC截图20191205160758.png](https://pic.leetcode-cn.com/35c868350ae3683828036ec35c5cdf93bd8d6db353958aea4852491bca708632-UC%E6%88%AA%E5%9B%BE20191205160758.png)

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return int(sum(nums) - (sum(nums) - sum(set(nums)))*1.5)

```