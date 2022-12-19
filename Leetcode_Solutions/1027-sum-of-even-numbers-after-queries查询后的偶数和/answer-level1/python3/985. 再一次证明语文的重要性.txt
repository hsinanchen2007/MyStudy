### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        origianl_sum = 0
        for item in A:
            if item % 2 == 0:
                origianl_sum += item                
        
        res = []
        for val, idx in queries:
            pre = A[idx]
            # 如果之前这个位置是偶数，先把他减去，再来判断这位置的数加上当前的修改是否是偶数，如果是偶数就再加上新的数就可以了
            if pre % 2 == 0:
                origianl_sum -= pre
            A[idx] = pre+val
            if A[idx] % 2 == 0:
                origianl_sum += A[idx]
            
            res.append(origianl_sum)

        
        return res


```