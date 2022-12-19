### 解题思路
首先统计相同数字的个数，然后找大于1 的公因子

### 代码

```python3


class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        if not deck or len(deck) == 1:
            return False
        deck.sort()
        # 1 1 2 2 3 3 4 4
        # 还是类似于双指针呗
        size_list = []
        size_min = len(deck)
        i = 0
        j = 0
        while i < len(deck) and j < len(deck):
            j = i
            count = 0
            while j + 1 < len(deck) and deck[j] == deck[j + 1]:
                count += 1
                j += 1
            count += 1
            # j就是相等时候的最后一个位置
            size_list.append(count)
            size_min = min(size_min, count)
            i = j + 1
        print(size_list)
        print(size_min)
        for i in range(2, size_min + 1):
            re = [bool(size % i == 0) for size in size_list]
            if all(re):
                return True
        return False
```