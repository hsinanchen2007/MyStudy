### 解题思路
执行用时 : 112 ms , 在所有 python3 提交中击败了 100.00% 的用户
内存消耗 : 14.1 MB , 在所有 python3 提交中击败了 100.00% 的用户

简单一句话：避免重复计算右边的最大值

### 代码

```python3
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        result = []
        def findMax(a , start):
            idx = start
            val = a[start] 
            for i in range(start , len(a)):
                if a[i] > val:
                    val = a[i]
                    idx = i
            return idx
        tmpIndex = findMax(arr , 0)
        for i in range(0 , len(arr) - 1):
            if i >= tmpIndex:
                tmpIndex = findMax(arr , i + 1)
            result.append(arr[tmpIndex])

        result.append(-1)
        return result
            
```