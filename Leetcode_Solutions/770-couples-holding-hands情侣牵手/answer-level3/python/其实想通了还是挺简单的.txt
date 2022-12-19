### 解题思路
1、按照题目的要求，一对情侣的数值分为两种情况：
	1）如果i是偶数，则为(row[i], row[i]+1)
	2）如果i是奇数，则为(row[i], row[i]-1)
2、从0到2N-1遍历，步进为2
	1）如果i和i+1是一对情侣数值，则继续遍历下一对
	2）如果i和i+1不是一对情侣，则把i的情侣找出来，和i+1进行交换

### 代码

```python3
class Solution(object):
    def minSwapsCouples(self, row: List[int]) -> int:
        exchange_count = 0
        for i in range(0, len(row), 2):
            lover_val = row[i] + 1 if row[i] % 2 == 0 else row[i] - 1
            if row[i+1] == lover_val:
                continue
            lover_pos = row.index(lover_val)
            row[i+1], row[lover_pos] = row[lover_pos], row[i+1]
            exchange_count += 1
        return exchange_count

```