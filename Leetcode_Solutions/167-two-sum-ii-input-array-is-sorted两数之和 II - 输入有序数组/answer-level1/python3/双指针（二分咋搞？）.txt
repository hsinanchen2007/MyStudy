### 解题思路
![image.png](https://pic.leetcode-cn.com/92f66a64dba89fe8f8dd203a9a702816cd02c92cce3a43e13ed2357cf71db8e5-image.png)

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers)-1
        while l < r:
            if numbers[l] + numbers[r] == target: 
                return [l+1,r+1]
            elif numbers[l] + numbers[r] < target:
                l += 1
            else:
                r -= 1
        return []
```