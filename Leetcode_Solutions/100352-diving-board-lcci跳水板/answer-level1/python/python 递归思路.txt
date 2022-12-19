分类标签说好的递归呢，递归变弟弟
测试用例 
shorter 1
longer  1
k       100000
```python3
    #只看递归思路，会超时
    def divingBoard2(self, shorter: int, longer: int, k: int) -> List[int]:
        # 0块板    0, 0
        # 1       shorter, longer
        # 2       rec(k-1)+shorter, rec(k-1)+longer
        def recursion(k):
            nonlocal re
            if k==0:return 0, 0
            if k==1:return shorter, longer
            min, max = recursion(k-1)
            return min+shorter, max+longer
        small, big = recursion(k)
        if longer-shorter==0 :return []
        re = list(range(small, big+1, longer-shorter))
        return re

    #正常解法
    def divingBoard(self, shorter: int, longer: int, k: int) -> List[int]:
        if k == 0:return []
        elif shorter == longer:
            return [k*shorter]
        return list(range(shorter*k, longer*k + 1, (longer-shorter)))
```
