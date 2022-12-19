# 大致思路
奇数位置的人不动，然后看偶数位置的人是否配对，如果不配对，找到配对人的位置，然后与之交换
```
class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        res = 0
        for i in range(0,len(row),2):  # 从左到右遍历奇数位置的人
            tag = row[i] + 1 if row[i] % 2 == 0 else row[i] - 1  # 计算与之配对的人
            if row[i + 1] != tag:  #  如果他与偶数位置的人不配对，则找到对的人并与之交换
                tag_index = row.index(tag)  #  找到匹配人的下标
                row[i + 1], row[tag_index] = row[tag_index], row[i + 1]  # 交换两个人
                res += 1  # 记录交换次数
        return res
```