### 解题思路
正确情况为两种：

1. 当前元素不为0，且其2倍存在于数组中
2. 当前元素为0，且0的个数不止一个

### 代码

```python3
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        cnt = collections.Counter(arr)
        for item in arr:
            if item != 0 and cnt[item * 2] != 0:
                return True
            if item == 0 and cnt[0] > 1:
                return True
        return False
```