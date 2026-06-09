```
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        uf = collections.defaultdict(int)
        cnt = collections.defaultdict(int)
        def find(p):
            while p != uf[p]:
                uf[p] = uf[uf[p]]
                p = uf[p]
            return p
        def union(p,q):
            rootp = find(p)
            rootq = find(q)
            if rootp == rootq:
                return
            else:
                if cnt[rootp] > cnt[rootq]:
                    uf[rootq] = rootp
                    cnt[rootp] += cnt[rootq]
                else:
                    uf[rootp] = rootq
                    cnt[rootq] += cnt[rootp]
        if not(len(nums)):
            return 0
        for n in nums:
            uf[n] = n
            cnt[n] = 1
        for n in nums:
            if cnt[n-1]:
                union(n,n-1)
            if cnt[n+1]:
                union(n,n+1)
        return max(cnt.values())
```

