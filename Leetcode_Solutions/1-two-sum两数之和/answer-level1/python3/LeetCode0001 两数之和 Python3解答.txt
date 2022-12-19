
![image.png](https://pic.leetcode-cn.com/4d716e0cff57ae91286a81932c35eeb2871212e55d2d8c11f60ad7c1ba10aecb-image.png)
```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l = list(map(lambda x: target-x, nums))
        for m in l:
            if m in nums:
                x = l.index(m)
                y = nums.index(m)
                if(x != y):
                    return [x,y]
                else:
                    if nums.count(m) > 1:
                        y = nums.index(m,y+1)
                        return [x,y]
```