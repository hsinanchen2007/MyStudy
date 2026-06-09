### 解题思路
1. 利用哈希表记录出现的次数，大于len(nums)/2就输出
2. 利用投票法来迭代计算出nums，主要利用的思想就是众数肯定会大于非众数之和。从而选出计数为正的数
3. 还有排序，排序取中值肯定是众数

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # med_num = len(nums) / 2
        # count = dict()
        # for i in nums:
        #     if i not in count:
        #         count[i] = 1
        #     else:
        #         count[i] += 1
        #     if count.get(i, 0) > med_num:
        #         return i

        count = 0
        res = None
        for i in nums:
            if count == 0:
                res = i
            count += 1 if res == i else -1
        return res
```