### 解题思路
1. sorted 对列表排序
2.  [:k] 切片

### 代码

```python3
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        return sorted(arr)[:k]
```
![屏幕快照 2020-02-14 21.33.58.png](https://pic.leetcode-cn.com/52d8814d5c21f9724df4ab80588114319e5f56c37b852f787d5616ea4b7c3713-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-14%2021.33.58.png)
