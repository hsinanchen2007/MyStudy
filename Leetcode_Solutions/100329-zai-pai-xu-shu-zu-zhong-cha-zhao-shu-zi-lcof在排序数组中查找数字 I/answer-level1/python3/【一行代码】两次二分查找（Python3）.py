# 线性扫描

## 思路

略

## 代码

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        cnt = 0
        for num in nums:
            if num == target:
                cnt += 1
        return cnt
```


**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$


# 二分

## 思路

我们二分查找到右侧边界， 再一次二分查找到左侧边界。 右侧边界 - 左侧边界间的距离就是我们要求的。


## 代码

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        return bisect.bisect(nums, target) - bisect.bisect_left(nums, target)
```


**复杂度分析**
- 时间复杂度：$O(logN)$
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)

