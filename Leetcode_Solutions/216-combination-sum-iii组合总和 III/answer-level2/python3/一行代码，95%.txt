给原函数加一个默认参数start=0
当k还剩1的时候判断n是否小于10
当k大于1的时候，判断n的一半，并且不能超过10
```
class Solution
    def combinationSum3(self, k: int, n: int, start=0) -> list:
        return ([[n]] if n < 10 else []) if k == 1 else [[i]+j for i in range(start+1, min((n+1)//2, 10)) for j in self.combinationSum3(k-1, n-i, i)]
```
