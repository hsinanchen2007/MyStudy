### 解题思路
首先排序
初始化最小绝对差为float("inf")，从第2个元素开始，记算它与前一个元素的差值，如果差值小于到目前为止的最小绝对差dif，那么更新dif为当前的差值，
并且res清空，添加当前答案。
如果等于dif，那么res直接添加
如果大于dif，略过

### 代码
```
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        res=[]
        dif=float("inf")
        n=len(arr)
        arr.sort()
        for i in range(1,n):
            tmp=arr[i]-arr[i-1]
            if tmp<dif:
                dif=tmp
                res=[]
                res.append([arr[i-1],arr[i]])
            elif tmp==dif:
                res.append([arr[i-1],arr[i]])
        return res
```
