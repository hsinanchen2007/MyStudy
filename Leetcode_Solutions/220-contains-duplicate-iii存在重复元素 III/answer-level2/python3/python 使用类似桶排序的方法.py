参考英文版LeetCode高赞方法
原址：[Java/Python one pass solution, O(n) time O(n) space using buckets](https://leetcode.com/problems/contains-duplicate-iii/discuss/61639)

思想类似桶排序算法。假设我们有宽度为(t+1)的连续的桶可以覆盖掉所有的数字范围，那么对于差的绝对值最大为t的两个数，有两种情况：
* （1）这两个数字在同一个桶中
* （2）这两个数字在相邻桶中

python代码
```python
def containsNearbyAlmostDuplicate(self, nums, k, t):
    if t < 0: return False
    n = len(nums)
    d = {}
    w = t + 1
    for i in range(n):
        m = nums[i] // w
        if m in d:
            return True
        if m - 1 in d and abs(nums[i] - d[m - 1]) < w:
            return True
        if m + 1 in d and abs(nums[i] - d[m + 1]) < w:
            return True
        d[m] = nums[i]
        if i >= k: del d[nums[i - k] // w]
    return False
```