### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        # 求所有数字出现次数的最大公约数，如果存在，则为True，否则为False
        dict = collections.Counter(deck)
        def gcd(x):
            imin = min(x)
            for i in reversed(range(2, imin + 1)):
                if list(filter(lambda j : j % i != 0, x)) == []:
                    return i
        count = set(dict.values())
        return True if gcd(count) else False

        


```