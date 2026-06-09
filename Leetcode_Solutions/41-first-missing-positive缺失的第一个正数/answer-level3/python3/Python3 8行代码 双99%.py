
想法很简单:
1.如果数组最小值为0或者负数，就让最小值变为1，然后依次+1直到nums中没有出现该值；
2.如果数组最小值大于1，则最小的正整数就是1，否则回到1。
```
def firstMissingPositive(self, nums: List[int]) -> int:
    if not nums: return 0
    _min = min(nums) if min(nums) > 0 else 1
    if _min > 1:
        return 1
    else:
        while _min in nums:
            _min += 1
        return _min
```
欢迎关注的[我的github](https://github.com/tcandzq)，查看更多精彩题解
![image.png](https://pic.leetcode-cn.com/ac076004e5031298eb05622bd5f5c62bb148042f0b330ad3d1079aea3cef1cac-image.png)
