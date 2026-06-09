### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def subarraysWithKDistinct(self, A: List[int], K: int) -> int:
        def atmost(K):
            res = 0
            dic=collections.defaultdict(int)
            l=0
            r = 0
            while r<len(A):
                dic[A[r]]+=1
                while len(dic)>K:
                    dic[A[l]]-=1
                    if dic[A[l]]==0:
                        del dic[A[l]]
                    l+=1
                res+=r-l+1
                r+=1
            return res

        return atmost(K)-atmost(K-1)

```