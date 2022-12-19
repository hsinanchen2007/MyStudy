这个题其实很明确了
总共就5, 10,  20元
但20元有 5+5+5 和 10+5 两种解决方案，又因为10元也需要5元，需要尽可能多的留5元
所以首先选取10 + 5其次选取5+5+5

```python3
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        money = {
            5: 0,
            10: 0
        }

        for bill in bills:
            if bill == 5:
                money[5] += 1
            elif bill == 10 and money[5] != 0:
                money[5] -= 1
                money[10] += 1
            elif bill == 20 and money[5] != 0 and money[10] != 0:
                money[5] -= 1
                money[10] -= 1
            elif bill == 20 and money[5] >= 3:
                money[5] -= 3
            else:
                return False
            # print(money)

        return True
```


![860.jpg](https://pic.leetcode-cn.com/62d287b8b8d8abb143f1a0e0b384fc936ddee94f3f217052601e5b642c5248a9-860.jpg)
