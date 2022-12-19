
```python
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        l = len(nums)
        if l % k:
            return False
        c = l // k
        count = collections.Counter([x % k for x in nums])
        return all(x == c for x in count.values())
```

上面这个题解我提交了

![image.png](https://pic.leetcode-cn.com/c8c457552c89355d2656c257dff174d3f3074c635a1b6926a13043d65b289105-image.png)


但很明显 ，如果  nums = [2,3,7] k=3,返回的是true,但明显这不是一个连续的数列

只能说准备的测试集太水了
