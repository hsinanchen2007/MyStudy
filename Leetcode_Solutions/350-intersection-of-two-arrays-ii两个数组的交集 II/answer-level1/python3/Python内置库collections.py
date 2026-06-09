Python的内置库collections有`Counter`等非常好用也好理解的函数。

`Counter`能将可以哈希的对象转换成一个字典，键就是元素，键值就是元素在对象中出现的次数

感觉应该比评论里第一的python做法要快一些，因为时间和空间都击败了95%+（2019.05.21）。评论里的高赞是一月的了.....应该有不少借鉴吧2333

```python
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        from collections import Counter
        nums1, nums2, ans = Counter(nums1), Counter(nums2), []
        for key in nums1.keys():
            try:
                ans += [key]*min(nums1[key], nums2[key])
            except KeyError:
                continue
        return ans
```