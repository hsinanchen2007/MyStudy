### 解题思路
[python bisect 库简介](https://codeplot.top/2019/11/15/%E8%AF%BB-Christoph-Durr-Jill-Jenn-Vie%E3%80%8A%E9%AB%98%E6%95%88%E7%AE%97%E6%B3%95%E2%80%94%E2%80%94%E7%AB%9E%E8%B5%9B%E3%80%81%E5%BA%94%E8%AF%95%E4%B8%8E%E6%8F%90%E9%AB%98%E5%BF%85%E4%BF%AE-128-%E4%BE%8B%E3%80%8B/#%E4%BA%8C%E5%88%86%E6%B3%95)


### 代码

```python
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        import bisect
        return bisect.bisect_left(nums, target)
```