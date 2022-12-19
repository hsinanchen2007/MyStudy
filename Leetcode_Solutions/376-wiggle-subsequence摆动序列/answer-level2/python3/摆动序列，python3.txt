### 解题思路
![摆动序列.png](https://pic.leetcode-cn.com/405ece5a38d3701217ef0bc70c48736608e7f9e23212c0ae05d0b79850e19e41-%E6%91%86%E5%8A%A8%E5%BA%8F%E5%88%97.png)

连续的三个值进行比较，如果三个值是递增的或者是递减的，就把中间值删掉
最后返回剩余列表长度

### 代码

```python3
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        if not nums or len(nums) == 1:
            return len(nums)
        if len(nums) == 2:
            if nums[0] == nums[1]:
                return 1
            else:
                return 2
        i = 1
        while i < len(nums)-1:
            if (nums[i]-nums[i-1])*(nums[i+1]-nums[i]) < 0:
                i += 1
                continue
            else:
                del nums[i]
        if len(nums) == 2:
            if nums[0] == nums[1]:
                return 1
            else:
                return 2
        return len(nums)
```