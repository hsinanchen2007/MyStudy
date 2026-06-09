```
class Solution:
    def combinationSum2(self, candidates, target):
        """
           1）首先这是一个典型的背包问题, 容量就是target, 物品就是candidate数组中的每个元素,
           且每个元素最多只能选择一次(还有一种情况是每个元素都可以无限量的选择), 选择每个物品的成本就是每个元素本身的值
           
           因为数组中可能有重复元素，所以首先使用一个字典存储所有unqiue元素及其对应的出现次数
           令f(i, v)表示扫描了前i个物品，并且消耗了容量v后可以获得的总的方案数, 那么状态转移
           方程就为:  f(i,v) = sum{f(i-1, v - k * candidates[i]), 0 <= k * candidates[i] <= target}

           也就是说第i个物品我们可以选择0个或多个

           2）此外，本题需要打印方案，这个应该是要使用一个递归打印出来所有的方案
        """
        if len(candidates) == 0:
            return []

        res = []
        # 存储每个元素及其对应的count，该count就是这个物品的约束，即在一个组合中最多不会超过count次
        value_count = {}
        for candidate in candidates:
            if candidate in value_count:
                value_count[candidate] = value_count.get(candidate) + 1
            else:
                value_count[candidate] = 1
        keys_ = list(value_count.keys())

        dp = [[0 for j in range(target+1)] for i in range(len(value_count)+1)]
        for i in range(1, len(keys_)+1):
            dp[i][0] = 1
        dp[0][0] = 1
        
        for i in range(1, len(keys_)+1):
            for j in range(1, target+1):
                # # 每个元素可以无限量选择
                # tmp_total_count = target // candidates[i-1]
                # for k in range(tmp_total_count + 1):
                #     if j - k * candidates[i-1] >= 0:
                #         dp[i][j] += dp[i-1][j - k * candidates[i-1]]
                
                
                if value_count.get(keys_[i-1]) == 1:
                    dp[i][j] += dp[i-1][j] + (dp[i-1][j-keys_[i-1]] if j-keys_[i-1]>=0 else 0)
                else:
                    tmp_count = value_count.get(keys_[i-1])
                    for k in range(tmp_count+1):
                        if j - k*keys_[i-1] >= 0:
                            dp[i][j] += dp[i-1][j - k*keys_[i-1]] 

        # 基于递归的方式取得所有的组合
        def helper(index, left_c, link_list):
            # 当剩余的容量为0时, 说明链接成功了, 加入到res中
            if left_c == 0:
                res.append(link_list)
                return
            tmp_count = min(left_c // keys_[index-1], value_count.get(keys_[index-1]))
            for k in range(tmp_count+1):
                if dp[index-1][left_c-k*keys_[index-1]] > 0:
                    helper(index-1, left_c-k*keys_[index-1], link_list+[keys_[index-1] for sk in range(k)])
        
        helper(len(keys_), target, [])
        
        return res
```
