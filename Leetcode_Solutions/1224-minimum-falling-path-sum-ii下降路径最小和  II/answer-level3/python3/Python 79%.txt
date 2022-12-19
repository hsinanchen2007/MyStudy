![image.png](https://pic.leetcode-cn.com/f4b0e250e4b71916a15f579c35f66ae316b0d1db70bc44d44196b55157d9b911-image.png)


```
class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        if not arr or not arr[0]:
            return 0
        for i in range(1,len(arr)):
            # 找 min 和 second min
            first_min = float("inf")
            second_min = float("inf")
            for value_j in arr[i-1]:
                if value_j<=first_min:
                    first_min,second_min = value_j,first_min
                elif value_j<=second_min:
                    second_min = value_j
            for j in range(len(arr[0])):
                arr[i][j] += second_min if arr[i-1][j]==first_min else first_min
        return min(arr[-1])
```

