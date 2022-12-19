```
        def find(l, r, s, target):
            if r > target // 2 + 1:
                return []
            if s == target:
                return [[i for i in range(l, r + 1)]] + find(l + 1, r + 1, s - l + r + 1, target)
            elif s < target:    
                return find(l, r + 1, s + r + 1, target)
            else:   
                return find(l + 1, r, s - l, target)
        return find(1, 2, 3, target)
```
分三种情况考虑就好了