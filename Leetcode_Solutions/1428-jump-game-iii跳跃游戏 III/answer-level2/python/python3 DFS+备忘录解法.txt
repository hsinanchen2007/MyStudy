# 思路
1. 当前坐标`i`加入备忘录，**目的： 如果后面又跳回来了，说明这是死循环，应当避免；**

2. 对下一个索引 `i + arr[i]` 和 `i - arr[i]` 进行dfs

# 代码
```python3
class Solution:
    def __init__(self):
        self.memo = set()
    
    def canReach(self, arr: List[int], start: int) -> bool:
        if 0 not in arr: 
            return False
        if arr[start] == 0: 
            return True
        nxt1, nxt2 = start + arr[start], start - arr[start]
        if 0 <= nxt1 < len(arr) and nxt1 not in self.memo:      # 如果当前坐标在memo中，则不应再dfs
            self.memo.add(nxt1)                                 # 加入当前坐标，避免后面跳回来了
            if self.canReach(arr, nxt1):                        # 剪枝，如果当前结果ok则直接返回
                return True             
        if 0 <= nxt2 < len(arr) and nxt2 not in self.memo:      # 对nxt2再进行相同的dfs
            self.memo.add(nxt2)
            if self.canReach(arr, nxt2):
                return True
        return False                                            # nxt1, nxt2都在memo中，或者对[0, arr.length)越界
```