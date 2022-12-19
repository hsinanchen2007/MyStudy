### 解题思路
这个地方很多人没解释清楚
- 题目定义的众数指出现次数超过所有数字的一半（那就是列表长度的一半）
- 排序以后众数紧凑在一起，看成整体
- 不管这个整体怎么移动，都会覆盖列表的中间位置，输出它就好

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        return sorted(nums)[len(nums)//2]
        

```