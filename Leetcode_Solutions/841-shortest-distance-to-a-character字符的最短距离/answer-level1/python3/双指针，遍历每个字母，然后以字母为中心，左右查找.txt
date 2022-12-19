### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        if C not in S:return -1

        left=right=0
        ans=[]
        for i in range(len(S)):
            left=right=i
            while S[left]!=C and S[right]!=C:
                left-=1
                right+=1
                if left<0:
                    left=0
                if right>len(S)-1:
                    right=len(S)-1
            if S[left]==C:
                ans.append(i-left)
            elif S[right]==C:
                ans.append(right-i)
        return ans 
                
        

                

```