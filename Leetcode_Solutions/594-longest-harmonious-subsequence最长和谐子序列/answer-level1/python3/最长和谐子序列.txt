### 解题思路
我的思路：字典统计个数，对字典按键从小到大排序，遍历字典，若键相差1则可能是解。
	

复杂度分析：                                                             
	• 时间复杂度：o(nlogn)
	• 空间复杂度：o(n)



### 代码

```python3
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        dicts = {}
        for x in nums:
            if x not in dicts:
                dicts[x] = 1
            else:
                dicts[x] += 1
        dicts_sorted = sorted(dicts.items(),key=lambda x:x[0])
        result = 0
        for i in range(len(dicts_sorted)-1):
            if dicts_sorted[i+1][0] - dicts_sorted[i][0] == 1:
                result = max(result,dicts_sorted[i][1]+dicts_sorted[i+1][1])
        return result 
```