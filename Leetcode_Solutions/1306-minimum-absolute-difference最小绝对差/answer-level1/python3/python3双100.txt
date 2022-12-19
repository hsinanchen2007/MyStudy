
```
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        if not arr:
            return []
        #列表排序
        arr.sort()
        res=[]
        #tmp:当前最小差值
        tmp=arr[1]-arr[0]
        for i in range(1,len(arr)):
            #出现更小差值后，更新结果
            if arr[i]-arr[i-1]<tmp:
                tmp=arr[i]-arr[i-1]
                res=[[arr[i-1],arr[i]]]
            #加入相同差值的数组
            elif arr[i]-arr[i-1]==tmp:
                res.append([arr[i-1],arr[i]])
            else:
                continue
        return res
```
