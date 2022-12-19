### 解题思路

十分简单，非常快。
![image.png](https://pic.leetcode-cn.com/71d714771ee612670785c81b7cb280a11413a3602859e650dcc3469e3b5a846e-image.png)

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr, k: int) -> List[int]:
        return sorted(arr)[:k]

```