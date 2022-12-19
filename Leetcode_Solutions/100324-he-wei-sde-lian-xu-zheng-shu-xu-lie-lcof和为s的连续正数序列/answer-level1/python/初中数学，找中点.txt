### 解题思路
- 根据序列长度找中点
- 根据序列长度与中点确定序列

### 代码

```python
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        i = 2
        res = []
        while target / i >= i / 2:  # 终止条件： 中点比序列半数小
            mid = target / i
			# 序列奇数个
            if mid % 1 == 0 and i % 2 == 1:
                res.append(list(range(int(mid - i // 2), int(mid + i // 2 + 1))))
			# 序列偶数个
            if mid % 1 == 0.5 and i % 2 == 0:
                res.append(list(range(int(mid + 0.5 - i // 2), int(mid - 0.5 + i // 2 + 1))))
            i += 1
        return res[::-1]
```