![image.png](https://pic.leetcode-cn.com/e853c409f2fa35792a8b20798f06cd23ddf756b2b248874e9f3fc8a870395d48-image.png)

哈希前缀和。

```python []
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        p, d = 0, {}
        for i, j in sorted(collections.Counter(nums).items()):
            d[i] = p
            p += j
        return [d[i] for i in nums]
```