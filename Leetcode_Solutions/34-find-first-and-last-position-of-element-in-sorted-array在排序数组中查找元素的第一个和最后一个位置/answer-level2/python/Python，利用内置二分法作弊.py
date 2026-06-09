### 解题思路
利用python内置的bisect模块的左查找、右查找，稍加判断即可。

### 结果
![image.png](https://pic.leetcode-cn.com/e8bd93d6ab2fcbbe6e7a45d5094f89d15360a2b8ba6a65f39922995e81411fb9-image.png)


### 代码

```python3
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        tmp = bisect.bisect(nums, target)
        indexR = tmp-1 if tmp>0 and nums[tmp-1]==target else -1

        tmp = bisect.bisect_left(nums, target)
        indexL = tmp if tmp<len(nums) and nums[tmp]==target else -1

        return [indexL, indexR]
```
个人公众号总结了一篇bisect模块的用法，欢迎关注
![image.png](https://pic.leetcode-cn.com/13cf64b28fd0610e0cdefe4a518dd6a2958af44dd8b8a089923212b178ee124a-image.png)
