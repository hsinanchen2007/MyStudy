轻优化
```
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        last_memery=[0]*(len(text1)+1)
        memery=[0]*(len(text1)+1)
        for i,t2 in enumerate(text2):
            memery=[0]*(len(text1)+1)
            for j,t1 in enumerate(text1):
                memery[j+1]=max(memery[j],last_memery[j+1],last_memery[j]+1 if t1==t2 else 0 )
            last_memery=memery
        # print(memery)
        return memery[-1] 
```
执行用时：340 ms  
超过98.89 % 的 python3 提交（在20200205时间）