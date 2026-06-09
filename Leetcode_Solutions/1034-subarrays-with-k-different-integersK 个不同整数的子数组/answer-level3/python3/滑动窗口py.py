### 解题思路
直接套用滑动窗口模板
需要注意的是左指针的移动条件，当左指针移动的时候 tmp++

### 代码

```python3
from collections import defaultdict
class Solution:
    def subarraysWithKDistinct(self, A: List[int], K: int) -> int:
        # 滑动窗口
        # base case 
        if A is None or len(A) < K:
            return 0
        hash = defaultdict(int)
        n = len(A)
        left = 0
        res = 0
        cnt = 0
        tmp = 1
        for i in range(n):
            hash[A[i]] += 1
            if hash[A[i]] == 1:
                cnt += 1
            # 移动左指针的条件，直到满足条件，这里需要注意的是左指针移动一次，算新来一个数!这个时候才tmp++,否则 tmp=1
            while hash[A[left]] > 1 or cnt > K:
                if cnt > K:
                    tmp = 1
                    cnt -= 1
                else:
                    tmp += 1
                hash[A[left]] -= 1
                left += 1
            if cnt == K:
                res += tmp
        return res




```