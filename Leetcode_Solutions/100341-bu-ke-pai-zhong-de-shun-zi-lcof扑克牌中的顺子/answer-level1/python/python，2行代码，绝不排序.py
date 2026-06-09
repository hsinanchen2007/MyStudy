### 解题思路
因为数值0（大小王）可以代替任何数值，所以先不管它，而仅考虑1-13之间的数值情况：
- 如果除0之外有重复值，那么肯定不是顺子
- 如果没有重复值，但其最大最小值跨度超过5，则无论用0怎么顶替也不会是顺子
- 否则（即无重复值且最大最小值跨度<5），则可以用其拼凑成顺子：区分数值连续还是不连续，都可以将0合理的补充构成顺子（加在两边或插入之间）

### 结果
![image.png](https://pic.leetcode-cn.com/0b31ccf6c33bd84b66665c237a8f27d2cb5be0141d077dcc644737b273682d84-image.png)

### 代码

```python3
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        nums = [num for num in nums if num] #筛选非0值
        return len(set(nums)) == len(nums) and max(nums)-min(nums) < 5 #判断非0值是否有重复及跨度区间
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)