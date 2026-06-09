### 解题思路
第一种情况：B的长度比A小，那么直接看B是不是A或者A*2的子串
第二种情况，B的长度更大，那么B可以分为3段：（A的末端一部分或全部）（A的N倍，N>=0）（A的前端一部分或空）
那么先匹配第一段，从A的末端，初始为A的长度，看这么长的B是不是A的一部分，不是的话长度就缩短1继续匹配，匹配成功记这一段长度L，
然后用整除操作求出中间有多少段A长度的整数倍，记为N,把这段切片，看等不等于N*A，不等于直接返回-1，等于的话记录N，继续
最后处理第三段，首先计算第三段长度，如果是0，那么结束，输出N+1,1是第一段所需要的一倍。如果大于0，那么从A的起始端匹配，匹配成功，输出N+2（第一段1，第二段N，第三段1），匹配失败返回-1


### 代码

```python3
class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        #如果B的长度更短，直接看B是不是A或A*2的子串
        if len(B)<len(A):
            if B in A:
                return 1
            if B not in A*2:
                return-1
            else:
                return 2
        #B更长的情况
        max_len=len(A)    #记录A的长度，用于B的起始和末尾的最大长度匹配
        l=0                 #记录第一部分的长度
        for i in range(max_len,0,-1):  #从最长的情况开始匹配
            if B[0:i]==A[max_len-i:]:   #如果这一段是A末尾的一部分，就得到第一段的长度，结束遍历
                l=i
                break
        time=(len(B)-l)//len(A)         #记录中间有几个A
        rest=len(B)-l-time*len(A)       #记录剩余的长度
        if B[l:l+time*len(A)]==A*time:  #B的中间部分和A的N倍直接比较，如果不相等就不是子串了
            if rest>0:                  #有剩余的部分
                if B[l+time*len(A):] == A[:rest]:   #看这一段是不是A起始的一部分
                    return time+2                   #是，符合，返回三段之和
                else:
                    return -1                       #不是，不符合，返回-1
            else:
                return time+1           #没有剩余的部分了，直接返回前两段之和
        else:
            return -1                   #B中间的部分不是A的N倍，不符合，返回-1
```