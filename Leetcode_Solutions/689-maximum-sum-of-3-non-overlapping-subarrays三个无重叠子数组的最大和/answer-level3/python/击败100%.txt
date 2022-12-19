![image.png](https://pic.leetcode-cn.com/b0a8c8cfb385e3a8279ae687ef091fc2e7b446265bcd660112f658ca62699c80-image.png)
1、首先计算以起点为i、长度为k的窗口的子数组和，存储为sums
2、遍历第2个子数组的起点p2，固定p2，选择p1，使sums[p1] + sums[p2]最大，等同于使sums[p1]最大，将此p1的指针存储于dp2[p2]中。
由于dp2[p2]相比于dp2[p2 - 1]，p1可选的值只多了一个(p2 - k)（也就是离第二个数组最近的子数组），故只需比较sums[dp2[p2-1]]和sums[p2-k]，即可决定p1（也就是dp2[p2]）的取值。无需嵌套循环遍历p1，因为其他取值都已经与dp2[p2-1]作过比较了。
以给出的用例为例：
p2 = 2时，dp2[2] = 0
p2 = 3时，dp2[3] = 0，不更新
p2 = 4时，dp2[4]还是0，不更新
p2 = 5时，p1可以取值0或3，由于sums[3] > sums[0]，即p1 = 3可使sums[p1] + sums[p2]最大，故dp2[p2] = dp2[5] = 3
p2 = 6时，p1从3和4中选择4，dp2[6] = 4
至此，“两个无重叠子数组的最大和”问题解决
3、在2的基础上，遍历第3个子数组的起点p3，固定p3，选择p2，使sums[p1] + sums[p2] + sums[p3]最大，将此p2存储于dp3[p3]中。
p1的值由dp2[p2]直接给出。
类似地，p2每次也只需从两个值里选其一，即dp3[p3 - 1]与p3 - k。
p3遍历完成后可得最终答案。

以上方法可扩展性较好，即使题目变成四个子数组的和，只需遍历p4并更新dp4即可。（官方解题中的left, right什么的，扩展起来比较麻烦的样子）
复杂度：总计3次遍历，O(n)。

```python
class Solution(object):
    def maxSumOfThreeSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        n = len(nums)
        s = 0
        sums = [0] * n
        for i in range(k):
            s += nums[i]
        for i in range(k, n):
            sums[i - k] = s
            s = s + nums[i] - nums[i - k]
        sums[n - k] = s
        
        dp2 = [0] * n
        dp3 = [k] * n
        
        for p2 in range(k, n - k + 1):
            max_p1 = dp2[p2 - 1]
            if sums[p2 - k] > sums[max_p1]:
                max_p1 = p2 - k
            dp2[p2] = max_p1
        
        ans = [0, k, 2 * k]
        for p3 in range(2 * k, n - k + 1):
            max_p2 = dp3[p3 - 1]
            if sums[p3 - k] + sums[dp2[p3 - k]] > sums[max_p2] + sums[dp2[max_p2]]:
                max_p2 = p3 - k
            dp3[p3] = max_p2
            if sums[p3] + sums[max_p2] + sums[dp2[max_p2]] > sums[ans[0]] + sums[ans[1]] + sums[ans[2]]:
                ans = [dp2[max_p2], max_p2, p3]
        return ans
```
