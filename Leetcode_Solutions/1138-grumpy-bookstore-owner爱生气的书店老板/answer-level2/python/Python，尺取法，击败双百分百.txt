首先非生气时的客户数量可以直接单独统计，把题目转换为：生气状态下，尺取范围内的最大客户数量。
```
# 优化的尺取法
class Solution(object):
    def maxSatisfied(self, customers, grumpy, X):
        """
        :type customers: List[int]
        :type grumpy: List[int]
        :type X: int
        :rtype: int
        """
        length = len(customers)
        if length <= X:
            return sum(customers)
        # 生气数组，非生气下的客户数量，秘密技巧下的最大客户数，生气数组的长度
        angry, ans, max_v, an_l = [], 0, 0, 0
        # 构建生气数组，并计算其长度；以及非生气下的客户数量（必然是满意的）
        for i in range(length):
            if grumpy[i] == 1:
                angry.append(i)
                an_l += 1
            else:
                ans += customers[i]
        # 当前尺度下的满足条件的客户数，尺取法的左右下标
        cur, left, right = 0, 0, 0
        while True:
            # 若在尺度范围内，则全部加起来。
            while right < an_l and angry[left] + X > angry[right]:
                cur += customers[angry[right]]
                right += 1
            # 如果该尺度范围内的客户数大于最大客户数，则更新最大客户数
            if cur > max_v:
                max_v = cur
            # 若右下标到达最右端则结束
            if right >= an_l:
                break
            # 删除左端在尺度范围外的客户数，已满足尺取
            while angry[right] - angry[left] >= X:
                cur -= customers[angry[left]]
                left += 1
        # 返回非生气下的客户数及抑制生气时的最大客户是，即最多的客户感到满足的数量
        return ans + max_v
        
```
