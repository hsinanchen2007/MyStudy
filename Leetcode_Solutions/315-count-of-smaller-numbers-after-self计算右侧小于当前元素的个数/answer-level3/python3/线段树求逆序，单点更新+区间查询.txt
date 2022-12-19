其实最优解可以将所有的数做一次序列化。
本来是为了简单，觉得 LC 数据量小就没做，结果因为处理负数情况还 WA 了两次得不偿失。
最佳解法：

1. 序列化成一个紧凑序列，全部映射到 `> 1` 区间（逆序数只看大小关系，所以 hash 保证大小关系即可）
2. 构造区间和线段树
3. 反向遍历数组，设每次元素为 N，执行 `query(1, N - 1)`
4. 更新 `update(N)`，计数 +1

```python
class Solution:
    
    def __init__(self):
        self.tree = []    
    
    def push_up(self, rt: int):
        self.tree[rt] = self.tree[rt * 2] + self.tree[rt * 2 + 1]
        
    def query(self, L: int, R: int, l: int, r: int, rt: int) -> int:
        if L <= l and r <= R:
            return self.tree[rt]    
        m, ret = (l + r) // 2, 0
        if L <= m:
            ret += self.query(L, R, l, m, rt * 2)
        if R > m:
            ret += self.query(L, R, m + 1, r, rt * 2 + 1)    
        return ret    
    
    def update(self, p: int, l: int, r: int, rt: int):
        if l == r:
            self.tree[rt] += 1
            return
        m = (l + r) // 2 
        if p <= m:
            self.update(p, l, m, rt * 2)
        else:
            self.update(p, m + 1, r, rt * 2 + 1)   
        self.push_up(rt)   

    def countSmaller(self, nums: List[int]) -> List[int]:
        if len(nums) == 0:
            return []
        if len(nums) == 1:
            return [0]
        if len(nums) == 2:
            if nums[0] > nums[1]:
                return [1, 0] 
            else:
                return [0, 0]
        minx = min(nums)
        if minx <= 0:
            for i in range(len(nums)):
                nums[i] = nums[i] - minx + 1
                
        maxn = max(nums)        
        # print(maxn, nums)
        self.tree = [0 for _ in range(1000000 * 4)]
        ret = []
        for i in range(len(nums) - 1, -1, -1):
            n = nums[i]
            #print(1, n, 1, maxn + 1, 1)
            ret.append(self.query(1, n - 1, 1, maxn, 1) if 1 != n else 0)
            #print(n + 1, 1, maxn, 1)
            self.update(n, 1, maxn, 1)
        return ret[::-1]
        
```