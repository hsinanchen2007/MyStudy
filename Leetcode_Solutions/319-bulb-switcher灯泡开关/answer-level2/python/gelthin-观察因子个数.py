### 解题思路
巧妙解法。
参照[题解](https://leetcode-cn.com/problems/bulb-switcher/solution/ru-guo-bu-shi-mo-ni-guo-cheng-bu-neng-tong-guo-shu/)

### 代码

```python3
class Solution:
    def bulbSwitch(self, n: int) -> int:
        import math  # 题解是在是太巧妙了，模拟法是无法通过的，完全平方数才会改变状态
        # 12 = 1,2,3,4,6,12 不亮，偶数个因子
        # 16 = 1,4,16 亮， 奇数个因子
        # [1, n] 有多少个完全平方数，sqrt(n) 个
        return int(math.sqrt(n))
```