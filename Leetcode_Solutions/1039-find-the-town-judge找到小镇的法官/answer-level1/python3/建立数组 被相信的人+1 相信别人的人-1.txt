代码很方便理解 我们建立一个数组
如果一个人被相信 那么他对应的index+1
如果一个人相信别人 那他对应的index-1
检查这个数组的最大值是不是等于N-1即可

```
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        arr = [0]* N
        length = len(trust)
        for i in range(0,length):
            arr[trust[i][1]-1] += 1
            arr[trust[i][0]-1] -= 1
        #print(arr)
        if max(arr) == N - 1:
            return arr.index(max(arr)) + 1
        else:
            return -1
```
