### 解题思路
暴力求解会时间超时，很多输入个例本身就是超长回文数，所以增加了对s本身的判定

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        #if len(s)<=1:
        #    return s
        if s==s[::-1]:#防超时tricktrick
            return s
        
        slices=[]           
        max_length=0
        for i in range(len(s)):
            subs=s[i:]
            end_idx=len(subs)
            
            for j in range(end_idx,-1,-1):
                if subs[:j]==subs[:j][::-1] and len(subs[:j])>max_length:
                    slices.append(subs[:j])
                    result = subs[:j]
                    max_length = len(subs[:j])
                    break


            

                

      
        return result#[max_length_index]


```