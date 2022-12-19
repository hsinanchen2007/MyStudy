![image.png](https://pic.leetcode-cn.com/8283a0e099e61749360af92d3a9067eda83f160eb7a255acf2d73c6a83c2b1e0-image.png)


无需多言，字典大法好

```Python []
def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if len(strs) <= 1: return [strs]
        dt = collections.defaultdict(list)
        for s in strs:
            dt[tuple(sorted(s))].append(s)
        return list(dt.values())
```


