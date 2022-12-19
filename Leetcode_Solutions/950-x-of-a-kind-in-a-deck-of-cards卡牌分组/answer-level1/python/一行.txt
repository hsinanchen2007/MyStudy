### 解题思路
求公约数是否大于1

### 代码

```python3
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        return reduce(math.gcd, collections.Counter(deck).values()) > 1


        # # 获取出现次数
        # counter = set(collections.Counter(deck).values())
        # min_count = min(counter)
        # # 如果存在出现一次, 则返回错误
        # if 1 in counter:
        #     return False
        # for i in range(2, min_count + 1):
        #     # 从2开始, 判断是否均可除尽
        #     if all([c % i == 0 for c in counter]):
        #         return True
        # return False
```