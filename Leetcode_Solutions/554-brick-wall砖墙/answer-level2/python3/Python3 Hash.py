class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        # 一共有m层，砖的数量最多为m层
        # 我们看看除了墙的两端，哪些位置会空出一条缝隙，就在该位置上减少一层砖
        # 最后再统计就好了
        from collections import defaultdict
        length = sum(wall[0])
        m = len(wall)
        brick_on_lines = defaultdict(lambda: m)
        for i in range(m):
            presum = 0
            for brick in wall[i][:-1]:      # 找出一层墙中的缝隙
                presum += brick
                brick_on_lines[presum] -= 1
        least_value = m
        for key, value in brick_on_lines.items():
            least_value = min(value, least_value)
        return least_value