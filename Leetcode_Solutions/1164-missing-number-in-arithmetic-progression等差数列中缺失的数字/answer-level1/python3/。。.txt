### 解题思路
我只能想到这个了

### 代码

```python3
class Solution:
    def missingNumber(self, arr: List[int]) -> int:
        x=0
        for i in range(0,len(arr),1):
            x=x+arr[i]
        return int(((arr[0]+arr[len(arr)-1])*(len(arr)+1))/2-x)

```