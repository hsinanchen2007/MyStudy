```python
        dp = {}  # 用来存储nums[i:j]的结果以避免重复计算
        def max_get(i, j) -> (int, int):  # 对nums[i:j]，先手能得到的最大分数，和该情况下后手得到的分数
            if (i, j) not in dp:  # 如果已计算则直接返回
                if j-i < 3:  # 如果为一位数或两位数，返回最大值（先手）和剩下的值（后手）
                    _max = max(nums[i:j])
                    dp[i, j] = _max, sum(nums[i:j])-_max
                else:  # 大于两位数
                    x1, y1 = max_get(i+1, j)  # 自己拿第一个数时，成为剩下数的后手，y1返回其还能拿到的最高分数
                    x2, y2 = max_get(i, j-1)  # 自己拿最后一个数，成为剩下数的后手，y2返回其还能拿到的最高分数
                    if nums[i]+y1 > nums[j-1]+y2:  # 返回拿第一个数或最后一个数时自己的更高分结果和对应的后手结果
                        dp[i, j] = nums[i]+y1, x1
                    else:
                        dp[i, j] = nums[j-1]+y2, x2
            return dp[i, j]
        
        if not len(nums)%2:  # 可以推一下，如果是偶数则先手必胜，去掉也行
            return True
        x, y = max_get(0, len(nums))
        return x >= y
```