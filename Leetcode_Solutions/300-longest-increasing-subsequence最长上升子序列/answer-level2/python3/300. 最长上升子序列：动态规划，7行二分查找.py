动态规划非常简单，属于传统做法，10年前搞oi的时候，一般都不要求做二分查找，当时的习惯是用动态规划婊搜索。

![image.png](https://pic.leetcode-cn.com/ceb322b13019e13c56c2a91f7ca852042c057b0503aa24cd0ac765e4226f6717-image.png)

```py
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0
        n = len(nums)
        d = [1] * n
        ans = 1
        for i in range(n):
            for j in range(i + 1, n):
                if nums[j] > nums[i]:
                    d[j] = max(d[j], d[i] + 1)
                    ans = max(ans, d[j])
        return ans
```

现在基本都要求做二分查找了，好在语言从c改到了Python，有系统函数给我用，代码更简洁了。

原理也不难，就是搞个升序队列，枚举数组里的数，如果插入值大于队列，就插在末尾，反之，就按查找到序号往左替换队列的值，时间复杂度是对数级。

队列搞个负无穷来初始化也是为了防止数据出现空集的情况。

![image.png](https://pic.leetcode-cn.com/eb6eb0c8a5da5869d143358e9d20cb791f56d65df4acb14e5827e9044e7b2092-image.png)


```py
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        q = [-float('inf')]
        for i in nums:
            if i > q[-1]:
                q += [i]
            else:
                q[bisect.bisect_left(q, i)] = i
        return len(q) - 1
```

```
【测试数组】（在样例上多加了两个数）
[10, 9, 2, 5, 3, 7, 101, 18, 4, 19]
【有效长度/队列/插入值】
1 [-inf, 10] <- 10
1 [-inf, 9] <- 9
1 [-inf, 2] <- 2
2 [-inf, 2, 5] <- 5
2 [-inf, 2, 3] <- 3
3 [-inf, 2, 3, 7] <- 7
4 [-inf, 2, 3, 7, 101] <- 101
4 [-inf, 2, 3, 7, 18] <- 18
4 [-inf, 2, 3, 4, 18] <- 4
5 [-inf, 2, 3, 4, 18, 19] <- 19
```
