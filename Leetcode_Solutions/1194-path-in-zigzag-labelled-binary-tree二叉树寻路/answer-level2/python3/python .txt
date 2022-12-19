```python
class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        path = []
        # Time complexity: O(logN)
        # Space complexity: O(1)
        while True:
            path.append(label)
            if label == 1: break
            layer = int(math.log(label, 2)) - 1
            left, right = 2 ** layer, 2 ** (layer + 1) - 1
            label = (left + right) - label // 2
        return path[::-1]
```