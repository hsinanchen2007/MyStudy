### 解题思路
用collection即可
![image.png](https://pic.leetcode-cn.com/07b3ade17631705adbe760eec628333c461b2a13cb9afe93a05776403f51c3da-image.png)

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        import collections
        s = collections.Counter(nums)
        for a in s:
            if s[a]>=2:
                return a
