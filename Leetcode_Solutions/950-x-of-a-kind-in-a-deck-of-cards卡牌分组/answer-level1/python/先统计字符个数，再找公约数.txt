### 解题思路
先统计字符个数，再找公约数

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        s = [deck.count(i) for i in set(deck)]
        print(s)
        for i in range(2,min(s) + 1):
            print(i)
            if all([j%i == 0 for j in s]):
                return True
        return False

```