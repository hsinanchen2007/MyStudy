```python
    def minSwapsCouples(self, row: List[int]) -> int:
        # 贪心算法
        n, res = len(row), 0
        for i in range(0, n, 2):  # 遍历所有座位对的第一个人
            mate = row[i] ^ 1  # 它的另一半为当前值异或1即将最后一位取反
            if row[i+1] != mate:  # 如果此时坐的不是它的另一半
                j = i+2+row[i+2:].index(mate)  # 找到它的另一半，直接从i+2找起节省时间
                row[i+1], row[j], res = row[j], row[i+1], res+1  # 交换
        return res
```
