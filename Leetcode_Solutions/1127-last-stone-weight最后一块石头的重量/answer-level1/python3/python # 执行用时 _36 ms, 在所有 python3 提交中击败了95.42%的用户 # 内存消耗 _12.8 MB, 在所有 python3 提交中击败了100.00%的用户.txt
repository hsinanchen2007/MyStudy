# 执行用时 :36 ms, 在所有 python3 提交中击败了95.42%的用户
# 内存消耗 :12.8 MB, 在所有 python3 提交中击败了100.00%的用户
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        while len(stones) > 1:
            y = stones.pop(stones.index(max(stones)))
            x = stones.pop(stones.index(max(stones)))
            if x == y:
                continue
            else:
                stones.append(y-x)
        if len(stones) == 1:
            return stones[0]
        return 0