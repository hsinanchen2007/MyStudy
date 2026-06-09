### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        return True if sorted(s1)==sorted(s2) else False
```![TIM截图20200329202554.png](https://pic.leetcode-cn.com/127d87d072e7853352a204f77d725f23e2d6cfd858a46e953ba70d286b09139c-TIM%E6%88%AA%E5%9B%BE20200329202554.png)
