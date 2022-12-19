### 解题思路
1. 倒序排列数组。
2. 得到倒序排列数组，遍历取得能构成三角形的连续三个值即可。


### 代码

```
class Solution:
    def largestPerimeter(self, A: List[int]) -> int:
        A.sort(reverse=True)
        print(A)
        for i in range(len(A)-2):
            print(i)
            if A[i+2]+A[i+1] > A[i]:
                return A[i]+A[i+1]+A[i+2]
        return 0
```