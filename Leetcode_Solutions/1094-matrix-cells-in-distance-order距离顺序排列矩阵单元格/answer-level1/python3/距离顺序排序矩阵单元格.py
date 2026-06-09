```python
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        res = []
        lens = []
        for r in range(R):
            for c in range(C):
                hl = abs(r - r0) + abs(c - c0)  # 计算曼哈顿距离
                while len(lens) < hl + 1:
                    lens.append(0)

                index = sum(lens[0:hl + 1])
                res.insert(index, [r, c])
                lens[hl] = lens[hl] + 1

        return res