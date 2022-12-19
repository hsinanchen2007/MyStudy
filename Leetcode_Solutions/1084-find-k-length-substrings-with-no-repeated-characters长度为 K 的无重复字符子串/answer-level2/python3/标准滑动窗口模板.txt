### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numKLenSubstrNoRepeats(self, S: str, K: int) -> int:
        if len(S)<K:
            return 0
        cnt = 0
        count = collections.defaultdict(int)
        left = 0
        ans = 0
        for right in range(len(S)):
            
            if count[S[right]]==1:
                cnt+=1
            count[S[right]]+=1
            while cnt>0:
                if count[S[left]]==2:
                    cnt-=1
                count[S[left]]-=1
                left+=1
            if right-left+1==K:
                ans+=1
                count[S[left]]-=1
                left+=1
        return ans

```