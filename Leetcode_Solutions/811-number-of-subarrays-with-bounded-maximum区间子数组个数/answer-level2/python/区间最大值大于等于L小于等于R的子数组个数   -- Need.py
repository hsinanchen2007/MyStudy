### 解题思路
1. 本人暴力解法，第一次暴力解法出问题了（i=j，但是 A[j] >= L and A[j] <= R 过小不满足条件），抄的他人的暴力解法
2. 有人采用“数学的间接方法”：区间最大值大于等于L小于等于R的子数组个数 = 区间最大值小于等于R的子数组个数 - 区间最大值小于等于L的子数组个数
3. 有人采用了DP思想。

### 代码

```python3
class Solution:
    def numSubarrayBoundedMax(self, A: List[int], L: int, R: int) -> int:
        nsize = len(A)
        i = 0
        ans = 0
        
        while i < nsize:
            nmax = 0
            j = i
            while j < nsize:
                if A[j] > nmax:
                    nmax = A[j]
                if nmax <= R:
                    if nmax >= L
                        ans += 1
                else:
                    break
                j += 1
            i += 1
        '''
        while i < nsize:
            if A[i] > R:
                i += 1
                continue
            j = i
            flag = False 
            while j < nsize:
                if A[j] > R:
                    break
                if A[j] >= L:
                    flag = True
                if flag:
                    ans += 1
                j += 1
            i += 1
        '''
        return ans 
```