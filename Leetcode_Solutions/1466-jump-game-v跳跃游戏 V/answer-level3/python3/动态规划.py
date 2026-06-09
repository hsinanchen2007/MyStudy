1. 最小规模是处于最低处，没处跳，等于1；
2. 再到第2小的位置，取出它能跳去的所有位置（在给定条件下，它能跳到的所有位置的最优解肯定会先得出),
结合这些位置算出最优解；
3. 依次进行直到最高处。 
```
class Solution:
    def maxJumps(self, arr: list, d: int):
        dp = [1] * len(arr)  # 储存每个位置最优解
        pos_sorted_by_val = sorted(enumerate(arr), key=lambda x: x[1])
        lowest = min(arr)
        for pos, val in pos_sorted_by_val:
            if val == lowest:  # 处于最低处
                dp[pos] = 1
            else:
                # 更新每个位置的最优解
                for prob_pos in self.get_probable_pos(arr, pos, d):
                    curr = 1 + dp[prob_pos]
                    dp[pos] = max(dp[pos], curr)
        return max(dp)

    def get_probable_pos(self, arr, i, d):
        """处于位置i时, 可以跳往的所有其它位置"""
        pos = []
        # steps为在当前arr的i位置可以使用的所有步长
        steps = list(range(max(-i, -d), min(len(arr) - i, d + 1)))
        left, right = steps[:steps.index(0)], steps[steps.index(0) + 1:]
        left.reverse()
        # 根据条件判断所有可能到达的位置
        for x in left:  # 判断向左跳有可能跳到的位置
            if not self.is_possible_pos(arr, i, x):
                break  # 如果该步长无处可跳,那么更长的步长也一定无处可跳
            pos.append(i + x)
        for x in right:
            if not self.is_possible_pos(arr, i, x):
                break
            pos.append(i + x)
        return pos

    def is_possible_pos(self, arr, i, x) -> bool:
        b = False
        # 计算中间所有障碍物的最大值（当|x|=1时,中间就是个空数组）
        k = 0 if x in (1, -1) else max(arr[min(i + x, i) + 1:max(i + x, i)])
        if arr[i + x] < arr[i] and k < arr[i]:
            b = True
        return b
```
