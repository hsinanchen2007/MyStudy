```python []
def trapModif(self, height: list) -> int:
        n = len(height)
        if n in (0, 1, 2):
            return 0
        i = 1
        ans = 0
        while i < n-1:
            l_max = i - 1 if height[i - 1] > height[i] else i
            if l_max != i:
                o = i + 1
                r_max = i
                while o < n:
                    if height[o] > height[i] and height[o] > height[r_max]:
                        r_max = o
                    if height[r_max] >= height[l_max]:
                        break
                    o += 1
            if l_max != i and r_max != i:
                ans += (r_max - i) * min(height[l_max], height[r_max]) - sum(height[i:r_max])
                i = r_max + 1
            else:
                i += 1
        return ans
```

