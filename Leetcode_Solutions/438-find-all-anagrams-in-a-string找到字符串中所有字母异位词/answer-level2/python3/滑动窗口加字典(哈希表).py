利用滑动窗口，每次右移在字典中添加/删除s中的元素,然后与p的字典比较，相同说明满足字母异位。
```
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if not s or not p:
            return []

        if len(p) > len(s):
            return []

        ans = []
        lenp = len(p)
        d = {}
        for i in p:
            d[i] = d.setdefault(i, 0)+1
        
        ds = {}
        for i in range(lenp):
            ds[s[i]] = ds.setdefault(s[i], 0)+1

        if ds == d:
            ans.append(0)

        ps = s[0]
        for i in range(1, len(s)-lenp+1):
            ds[ps] -= 1
            if ds[ps] == 0:
                ds.pop(ps)
            ps = s[i]
            ds[s[i+lenp-1]] = ds.setdefault(s[i+lenp-1], 0)+1

            if ds == d:
                ans.append(i)

        return ans
```
