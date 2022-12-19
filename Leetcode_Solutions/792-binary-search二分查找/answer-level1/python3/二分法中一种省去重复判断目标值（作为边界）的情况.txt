### 解题思路
此处撰写解题思路

在一般的解题思路下，elif与else各增加了一个判断，省去了重复操作的时间(比如目标值和中值的原来上，下限之一相等的下去掉目标值作为边界的情况)
![图片1.png](https://pic.leetcode-cn.com/9864b9365c41e482d1e4d6957e8e08714867aa45b24a2771fc2ab449ee8562d6-%E5%9B%BE%E7%89%871.png)
空间复杂度还是很高，再想想
### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low, high = 0, len(nums) -1
 
        while low <= high:
            mid = (low + high)//2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                if nums[low] ==  target:
                    return low
                else:high = mid - 1
            else:
                if nums[high] ==  target:
                    return high
                else:low = mid + 1
        
        return -1
```