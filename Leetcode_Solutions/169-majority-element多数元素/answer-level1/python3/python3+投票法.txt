### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        half_count = len(nums) / 2
        count_map = {}
        for num in nums:
            count_map[num] = count_map.get(num, 0) + 1
            if count_map[num] > half_count:
                return num
        # print(count_map)
        # count_map = sorted(count_map.items(), key=lambda item: item[1], reverse=True)
        # return count_map[0][0]
```