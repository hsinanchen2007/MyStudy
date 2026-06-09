时间复杂度o(n),空间复杂度o(1)
```
class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        n = len(arrays)
        j = 0
        while not arrays[j]:
            j += 1
        l = arrays[j][0] #初始化历史最小值
        r = arrays[j][-1] #初始化历史最大值
        ans = 0
        for i in range(j+1,n):
            #更新数组列表的最大距离
            ans = max(ans,abs(arrays[i][-1]-l))
            ans = max(ans,abs(arrays[i][0]-r))
            #维护历史最小值l和历史最大值r
            l = min(l,arrays[i][0])
            r = max(r,arrays[i][-1])
        return ans
```
