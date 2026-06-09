### 解题思路
此处撰写解题思路
![微信图片_20200226224317.jpg](https://pic.leetcode-cn.com/c632cf65b70dcd9b7de6a513b8128543ca72ce81108ec4026af588f0121ad8c8-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200226224317.jpg)


### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        i,j = 0,1
        ret = []
        mid = target // 2 +2
        nums = list(range(1, mid))
        while i <= mid-1 and j<= mid:
            total = sum(nums[i:j])
            if total > target:
                i +=1
            elif total < target:
                j += 1
            else:
                ret.append(nums[i:j])
                i += 1
                j += 1
                
        return ret
```