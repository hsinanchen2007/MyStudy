### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        ans = [[arr[0],arr[1]]]
        Min = arr[1]-arr[0]
        n = len(arr)
        for i in range(2,n):
            temp = arr[i]-arr[i-1]
            if temp ==Min:
                ans.append([arr[i-1],arr[i]])
            if temp<Min:
                Min = temp
                ans =  [ [arr[i-1],arr[i]] ]
        return ans
```