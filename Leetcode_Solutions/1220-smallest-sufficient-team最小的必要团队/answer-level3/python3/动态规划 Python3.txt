**思路：**

本题是一个 [集合覆盖问题](https://baike.baidu.com/item/%E9%9B%86%E5%90%88%E8%A6%86%E7%9B%96%E9%97%AE%E9%A2%98/9160069)，[决定性问题](https://baike.baidu.com/item/决定性问题) 的集合覆盖是 [NP完全问题](https://baike.baidu.com/item/NP完全问题)，最佳化问题的集合覆盖是NP困难问题。所以想得到最优解（之一），只能用暴力搜索。好在数据范围并不大，最大状态空间也只有 $2^{16}=65,536‬$ 种状态，也就是 $16$ 个人每个人有选和不选两种情况。我们可以用动态规划的方法进行搜索。先将 `req_skills` 的全集建立一个字典，对每个技能进行编号 `0 ~ n-1` 。然后建立 `dp` 数组，长度为 $2^n$ ，数组元素初始化为 `people` 的全集，然后对 `dp[0]` 初始化为空集。然后我们遍历每个人，对于所有状态，计算把这个人加入团队后，整个团队的技能是否增加，如果增加并且人数比拥有相同技能的团队更优化，则更新结果。最终，全集 `dp[(1 << n) - 1]` 中的 `people` 集合就是我们要求的结果。


**代码：**
```python [-Python]
class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        # 为skills建立字典
        n = len(req_skills)
        d = dict()
        for i in range(n):
            d[req_skills[i]] = i
        # 所有状态
        dp = [list(range(len(people))) for _ in range(1 << n)]
        dp[0] = []
        # 遍历所有人
        for i in range(len(people)):
            # 求这个人的技能
            skill = 0
            for s in people[i]:
                skill |= (1 << d[s])
            for k, v in enumerate(dp):
                # 把这个人加入进来以后的团队技能
                new_skills = k | skill
                # 如果团队技能因此而增加 并且增加后的人数比新技能原来的人数少 则更新答案
                if new_skills != k and len(dp[new_skills]) > len(v) + 1:
                    dp[new_skills] = v + [i]
        return dp[(1 << n) - 1]
```
