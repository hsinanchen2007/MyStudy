![微信图片编辑_20200213170845.jpg](https://pic.leetcode-cn.com/f9d39d0221fb6c6cf490eeb7f96063d5ae97dff24aa17eb1027a4a62739a5537-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87%E7%BC%96%E8%BE%91_20200213170845.jpg)

利用数学公式：1+2+···+n = n*(n+1)//2
```
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)
        s=n*(n+1)//2-sum(nums)
        return s
```
