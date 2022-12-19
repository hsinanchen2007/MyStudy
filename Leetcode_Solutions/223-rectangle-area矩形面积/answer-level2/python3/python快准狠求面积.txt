注意别忘了还有不重叠的情况啊,
```python3

        left_max,right_min,up_min,down_max = max(A, E),min(C, G),min(D, H),max(B, F)
        if left_max <= right_min and up_min >= down_max:
            return (D - B) * (C - A) + (G - E) * (H - F) - (right_min - left_max)*(up_min - down_max)
        else:
            return (D - B) * (C - A) + (G - E) * (H - F)
```
