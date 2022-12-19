### 解题思路
用一个哈希表记录之前出现过的数的和以及对应的下标，遍历所有的数，直接查找k - nums[i]是否在哈希表中。

### 代码

```python
class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return 0
        temp = 0
        sum_dict = {0: [-1]}
        cnt = 0
        for i in range(length):
            temp += nums[i]
            if temp - k in sum_dict:
                cnt += len(sum_dict[temp - k])
            if temp in sum_dict:
                sum_dict[temp].append(i)
            else:
                sum_dict[temp] = [i]

        print(sum_dict)
        return cnt

    def subarraySum_2(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return 0
        temp = 0
        sum_dict = {0: [-1]}
        for i in range(length):
            temp += nums[i]
            if temp in sum_dict:
                sum_dict[temp].append(i)
            else:
                sum_dict[temp] = [i]
        cnt = 0
        print(sum_dict)
        for temp in sum_dict:
            for ind in sum_dict[temp]:
                if temp + k in sum_dict:
                    cnt += len(list(filter(lambda x: x - ind > 0, sum_dict[temp + k])))
        return cnt
```