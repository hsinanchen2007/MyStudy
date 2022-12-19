

我们遍历一次数组，如果是偶数，则插入到末尾，如果是奇数，则插入到头部即可。


```python
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        res = []

        for num in nums:
            if num % 2 == 0:
                res.append(num)
            else:
                res.insert(0, num)
        return res
```

**复杂度分析**

- 时间复杂度：$O(N)$，其中N为数组长度。
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)