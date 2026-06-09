```
class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr = sorted(arr)
        index = arr[1] - arr[0]
        ans = [[arr[0],arr[1]]]
        for i in range(1,len(arr)-1):
            m = arr[i+1] - arr[i]
            if m < index:
                ans.clear()
                ans.append([arr[i],arr[i+1]])
                index = m
            elif m == index:
                ans.append([arr[i],arr[i+1]])
            else:
                continue
        return sorted(ans)

```
