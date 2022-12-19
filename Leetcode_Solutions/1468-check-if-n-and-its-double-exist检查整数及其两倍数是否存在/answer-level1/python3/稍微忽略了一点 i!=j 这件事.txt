### 解题思路
列表中的元素，逐个乘2，判断是否还在原列表中。

注意：
一开始还在想，怎么可能有一个数的两倍是自身，所以不需要考虑 i==j 的情况，完全忽略了0的二倍还是0，所以要加入判断 i!=j。
举个例子说明一下：
如果  [10,0,1] → 0 与 2*0 的 index 在同一位置 → False
如果  [10,0,0] → 0 与 2*0 的 index 可以不在同一位置 → True

### 代码

```
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        for idx, item in enumerate(arr):
            double = 2 * item
            if double in arr and arr.index(double) != idx:
                return True
        
        return False
```