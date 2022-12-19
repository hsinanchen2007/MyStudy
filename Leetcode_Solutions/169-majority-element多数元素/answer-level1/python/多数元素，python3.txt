### 解题思路
如果`nums`中的众数记为`1`，非众数记为`-1`，那么`sum(nums)`一定大于`0`
我们假设众数`res`为`nums[0]`，`nums`中`index`从`0`到`i`的元素累加和我们记为`count`，`count`初始化为`0`
遍历`nums`：
- 如果此时`count>0`，说明`res`是`nums[:i]`的众数
    - 如果`nums[i]==res`，说明`res`是`nums[:i+1]`的众数，`count`加`1`，继续遍历
    - 否则`count`减`1`
- 如果`count<=0`，说明`res`已经不是`nums[:i]`的众数了，我们需要找一个新的候选者，我们让`nums[i]`做这个候选者，`count`加`1`


### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res = nums[0]
        count = 0
        for i in nums:
            if count > 0:
                if i == res:
                    count += 1
                else:
                    count -= 1
            else:
                res = i
                count += 1
        return res
```