![f92643a3d583db56afc7510c201c4d4.png](https://pic.leetcode-cn.com/cc1b778fcfdd37f95df69608b56fbfd80ad705f02c3f601a6bb34a9e0a1c2bf5-f92643a3d583db56afc7510c201c4d4.png)
##### 这道题的内核是《算法导论》P38的最大子数组问题。
《导论》介绍了分治法，其时间复杂度为O(nlogn)。这里写出O(n)的方法，没有分治法漂亮但更实用。思路是一次遍历数组，保存每一步的最大子数组和的信息。
```python []
class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        def max_sub(arr):
            """
            定义函数max_sub用来求最大子数组之和
            """
            max_sum = 0  ## 设立max_sum用来存放所有子数组里最大的和
            moving_sum = 0  ## 设立moving_sum用来存放以i为右下标的子数组里最大的和
            n = len(arr)  ## n是arr的长度
            for i in range(n):  ## 遍历数组
                moving_sum += arr[i]
                if moving_sum < 0:  ## 下一个 moving_sum 要么是上一个 moving_sum 加上arr[i]，要么是0
                    moving_sum = 0 
                elif moving_sum > max_sum:
                    max_sum = moving_sum  ## moving_sum 比记录的 max_sum 大的话，那么新的 max_sum 就是 moving_sum
            return max_sum ## 一遍遍历下来的max_sum就是最大子数组的和



        if k == 1:  ## 如果k是1，那么就是求 arr 的最大子数组的和
            res = max_sub(arr)

        elif k == 2:  ## 如果k是2，那么就是求 arr * 2 的最大子数组的和
            res = max_sub(arr * 2)

        elif k > 2:
            one_arr = sum(arr)
            if one_arr > 0:  ## 如果 k > 2，并且 sum(arr)>0，那么相当于 arr * 2 的情形中间加塞了k-2段arr
                res = (k - 2) * one_arr + max_sub(arr * 2)
            else:  ## 如果 k > 2，并且 sum(arr)<=0，那么就是求 arr * 2 的最大子数组的和
                res = max_sub(arr * 2)

        return res % (10 ** 9 + 7)  ## 结果模一个质数，避免过大

```

