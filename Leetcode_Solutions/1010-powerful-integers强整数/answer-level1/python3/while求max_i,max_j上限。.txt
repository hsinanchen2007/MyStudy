第二遍遍历时可以brake掉一些循环，居然耗时比没break多，不科学
```
def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        res = set()
        max_i, max_j = 0, 0,
        if x == 1:
            max_i = 1
        else:
            while x**max_i < bound:
                max_i += 1;
        if y == 1:
            max_j = 1
        else:
            while y**max_j < bound:
                max_j += 1;

        for i in range(max_i):
            for j in range(max_j):
                a = x**i + y**j
                if a <= bound:
                    res.add(a)
                else:
                    break
        return list(res)
```
