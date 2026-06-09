### 解题思路
与上一题一样的思路，回溯（带剪枝）+去重，这次的回溯的不同在于当前结点下标为i，那么分裂出去的下一层待选结点将从(i,len(candidates)]中去找。时间复杂度为O(n^2)。

### 代码

```python3
class Solution:
    def combinationSum2(self, candidates:list, target: int):
        # 去重
        def isrepeat(a, b):
            lenA = len(a)
            lenB = len(b)
            if lenA != lenB or set(a) != set(b):  # 长度不等或元素种类不同的，不是重复的
                return False
            A = {}
            for val in a:  # 用字典去判断各种类元素个数是否相等
                if not A.get(val):
                    A[val] = 1
                else:
                    A[val] += 1
            for val in b:
                if A[val] > 0:
                    A[val] -= 1
                else:
                    return False
            return True
        def search(pre_sum,start):
            for i in range(start,len(candidates)):
                val = candidates[i]
                if pre_sum+val==target:
                    tmp.append(val)
                    res.append(tmp.copy())
                    tmp.pop()
                    return
                elif pre_sum+val<target:
                    tmp.append(val)
                    search(pre_sum+val,i+1)
                    tmp.pop()
                else:
                    return
        res = []
        tmp = []
        #搜索
        candidates.sort()
        search(0,0)

        needed = [True]*len(res)
        for i in range(len(res)-1):
            if not needed[i]:
                continue
            for j in range(i+1,len(res)):
                if needed and isrepeat(res[i],res[j]):
                    needed[j]=False
        res = [res[i] for i in range(len(res)) if needed[i]]
        return res
```