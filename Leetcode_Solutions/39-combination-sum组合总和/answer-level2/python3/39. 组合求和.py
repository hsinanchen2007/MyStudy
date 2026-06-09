### 解题思路
排列组合的题，我首先想到的是回溯+剪枝，这份代码的思路首先是找出所有符合要求的组合，然后进行去重；剪枝是先把candidates按升序排序，这样，在当前层找到相等或大于target的值后，便可以return。

### 代码

```python3
class Solution:
    def combinationSum(self, candidates, target: int):
        def isrepeat(a, b):
            lenA = len(a)
            lenB = len(b)
            if lenA!=lenB or set(a)!=set(b):
                return False
            A = {}
            for val in a:
                if not A.get(val):
                    A[val]=1
                else:
                    A[val]+=1
            for val in b:
                if A[val]>0:
                    A[val]-=1
                else:
                    return False
            return True
        def search(pre_sum):
            for val in candidates:
                if pre_sum+val==target:
                    tmp.append(val)
                    res.append(tmp.copy())
                    tmp.pop()
                    return
                elif pre_sum+val<target:
                    tmp.append(val)
                    search(pre_sum+val)
                    tmp.pop()
                else:
                    return

        res = []
        tmp = []
        candidates.sort()
        search(0)
        needed = [True]*len(res)
        for i in range(len(res)-1):
            if not needed[i]:
                continue
            for j in range(i+1,len(res)):
                if needed[j] and isrepeat(res[i],res[j]):  #利用集合筛选元素重复的列表
                    needed[j]=False
        res = [res[i] for i in range(len(res)) if needed[i]]
        return res
```