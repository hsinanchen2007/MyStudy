# 题解
## 栈+排序
括号匹配，第一时间想到用栈进行匹配，保存下可以匹配的索引下标。然后将匹配索引排序，找到最长连续子序列。

 1. 初试化栈$stack=[]$和匹配索引数组$res=[]$
 2. 遍历括号字符串：
 	+ 若$s[i]=="("$，若出现左括号，将其索引加入栈。
 	+ 若$stack$不为空且$s[i]==")"$，表示出现右括号，且栈里有左括号。
 		+ 将匹配的左括号的索引$stack.pop()$加入$res$中
 		+ 将匹配的右括号索引$i$加入栈。
 
 3. 将$res$排序。
 4. 初始化最长长度$max\_len=0$，寻找$res$的最长连续子序列。循环条件，$i<len(res)-1$：
 	+ 令$tmp=i$保存最长连续子序列的左界
 	+ 进入循环，循环条件$i<len(res)-1$且下一位和当前位差为1$res[i+1]-res[i]==1$：
 		+ 令$i=i+1$
 	+ $max\_len=max(max\_len,i-tmp+1)$
 	+ i+=1
 
 5. 返回$max\_len$

 

 
### 复杂度分析
 - 时间复杂度：$O\left(nlog(n)\right)$，括号匹配$O(n)$，排序复杂度$O\left(nlog(n)\right)$，寻找最长连续子序列$O(n)$，总体$O\left(nlog(n)\right)$
 - 空间复杂度：$O(n)$

### Python

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        res=[]
        stack=[]
        for i in range(len(s)):
            if(stack and s[i]==")"):
                res.append(stack.pop())
                res.append(i)
            if(s[i]=="("):
                stack.append(i)
        #print(res)
        res.sort()
        max_len=0
        i=0
        while(i<len(res)-1):
            tmp=i
            while(i<len(res)-1 and res[i+1]-res[i]==1):
                i+=1
            max_len=max(max_len,i-tmp+1)
            i+=1
        return max_len
```

## 栈 优化（不排序）
 1. 特判，若$s$为空，返回$0$
 2. 初试化栈$stack=[-1]$，和结果$res=0$。栈中元素表示上一不匹配位置索引。
 3. 遍历$s$：
 	+ 若$s[i]=="("$，将当前位置索引加入$stack$。表示将当前左括号需要匹配，为不匹配索引。
 	+ 若$s[i]==")"$：
 		+ 出栈，$stack.pop()$。表示将对应左括号索引出栈，或者当栈中只有$)$时，将上一$)$索引出栈。
 		+ 若栈为空，表示之前的所有的$($匹配成功，上一步出栈的是栈底的$-1$或者是前一个不匹配的$)$。则更新栈底为当前$)$的索引，表示不匹配的位置。
 		+ 否则，说明和栈中的$($匹配上了，此时更新最长序列$res=max(res,i-stack[-1])$。表示当前位置索引减去上一不匹配位置索引 和之前$res$中的较大值。
 
 4. 更新$res$

### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(n)$

### Python

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if(not s):
            return 0
        stack=[-1]
        res=0
        for i in range(len(s)):
            if(s[i]=="("):
                stack.append(i)
            else:
                stack.pop()
                if(not stack):
                    stack.append(i)
                else:
                    res=max(res,i-stack[-1])
        return res
```

## 动态规划
 1. 特判，若$s$为空，返回$0$
 2. 初试化$dp=[0,...,0]$，长度为$n$。$dp[i]$表示到$i$位置的最长有效括号的长度。
**显然**，当$s[i]$为$($时，$dp[i]=0$
 3. 遍历字符串，遍历区间$[1,n)$：
 	+ 当$s[i]==)$时，若$s[i-1]==($，说明这两个有效。则$dp[i]=dp[i-2]+2$
 	+ 否则$s[i-1]==)$，此时找到上一匹配字符串的上一位$i-dp[i-1]-1$：
 		+ 若$s[i-dp[i-1]-1]==($，说明$s[i]$可以和$s[i-dp[i-1]-1]$匹配：则$dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2$，表示当前位置的最长有效括号长度等于上一位有效括号的长度加上自身匹配的上一位的有效括号的长度加上2。
 	+ 更新$res$，$res=max(res,dp[i])$
 
 5. 返回$res$

### 复杂度分析
 - 时间复杂度：$O\left(n\right)$
 - 空间复杂度：$O(1)$

### Python

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        if(not s):
            return 0
        res=0
        n=len(s)
        dp=[0]*n
        for i in range(1,len(s)):
            if(s[i]==")"):
                if(s[i-1]=="("):
                    dp[i]=dp[i-2]+2
                if(s[i-1]==")" and i-dp[i-1]-1>=0 and s[i-dp[i-1]-1]=="("):
                    dp[i]=dp[i-1]+dp[i-dp[i-1]-2]+2
                res=max(res,dp[i])
        return res
```
