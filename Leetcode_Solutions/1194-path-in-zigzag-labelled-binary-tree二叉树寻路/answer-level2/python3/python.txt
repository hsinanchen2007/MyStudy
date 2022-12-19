```python
class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        
        # label: 14 layer: 4
        # label: 4, layer: 3
        # label: 3, layer: 2
        # label: 1, layer: 1
        
        def update(val, layer):
            left = 2 ** (layer - 2)
            right = 2 ** (layer - 1) - 1
            return left + right - val // 2
        
        res = []
        layer = int(math.log(label, 2)) + 1
        while label != 1:
            res.append(label)
            label = update(label, layer)
            layer -= 1
        res.append(label)
        return res[::-1]
```