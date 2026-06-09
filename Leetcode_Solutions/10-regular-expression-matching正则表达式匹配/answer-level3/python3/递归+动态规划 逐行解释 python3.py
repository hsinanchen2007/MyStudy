# 题解
## 递归

 递归函数$isMatch(s,p)$，$s$表示待匹配字符，$p$表示字符规律
 

 1. 若$p$为空，此时返回$s$是否为空。表示若字符规律已经为空，若$s$还不为空，此时匹配失败。若为空，表示匹配成功。
 2. 定义$pre$表示$s$和$p$第一位是否匹配成功。 匹配条件：$s$不能为空且$p[0]==s[0]\ or\ "."$。表示$p$的第一位等于$s$的第一位，或者$p[0]=="."$可以匹配所有字符。
 3. 若$p$中有$*$字符，条件$len(p)>=2\ and\ p[1]==*$，表示第二位为$*$。即有字符和$*$相连。对应两种情况。
 	+ 跳过这两个字符，表示这个字符出现零次。即$isMatch(s,p[2:])$---此处不理解，看我的**注意！**
 	+ 首位匹配成功，继续匹配$s[1:]$和$p$，即$pre\ and\ isMatch(s[1:],p)$
 4. 若无$*$则，继续匹配，返回$pre\ and\ isMatch(s[1:],p[1:])$

 
 **注意！**
 字符$+*$是一个整体，表示这个字符出现0次或者多次！ 经过我的测试，测试用例*不能单独出现，一定跟在字符后
 如下两种测试用例，前一种会报错，后一种不会。
 
![在这里插入图片描述](https://pic.leetcode-cn.com/d26bf679418d66cfb595323cc4f1dc4a420967eb9bf2ebab8fb813f0d96b6f4d.png)
![在这里插入图片描述](https://pic.leetcode-cn.com/4cac7d4117dc872ea82ea1491792bc8c5778637304351f2e9ff4ff21d3129d21.png)
### 复杂度分析
 - 时间复杂度：$O\left((S+P)*2^{S+\frac{P}{2}}\right)$，具体分析略。$S$表示$s$的长度，$P$表示$p$的长度。
 - 空间复杂度：$O\left((S+P)*2^{S+\frac{P}{2}}\right)$

### Python

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p:
             return not s
        first = bool(s) and p[0] in {s[0], '.'}
        if len(p) >= 2 and p[1] == '*':
            return self.isMatch(s, p[2:]) or first and self.isMatch(s[1:], p)
        else:
            return first and self.isMatch(s[1:], p[1:])
```

## 动态规划法
**重叠子问题结构**

 1. 初始化$s$的长度$S$，$p$的长度$P$
 2. 初始化哈希表$memo=\{\}$，键为$(i,j)$，值为$True\ or\ False$，表示$s[0,...,i]$和$p[0,...,j]$是否匹配。
 3. 定义递归函数$dp(i,j)$，$i$为当前$s$的匹配位置，$j$为$p$的匹配位置。
 	+ 若$(i,j)$出现在$memo$中，表示当前子问题，之前已经处理过，直接返回对应的值，$memo[(i,j)]$
 	+ 若$j==P$，说明$p$已经匹配完，若此时$s$还有字符未匹配，则返回$False$，若$s$也匹配完，则返回$True$。即返回$i==S$ 
 	+ 定义$pre$表示当前$p$和$s$的首位是否匹配。条件：$i<S$表示$s$是否遍历完。且$p[j]$是否等于$s[i]$或$"."$。$pre= i<S\ and\ p[j]\ in\ \{s[i],"."\}$。
 	+ 判断是否存在$*$字符，条件：$j<=P-2$表示是否还剩两个字符以上，且$p[j+1]$为$*$：
 		+ 跳过这两个字符，表示匹配$0$次，$dp(i,j+2)$
 		+ 首位匹配成功，继续匹配下一位，$pre\ and\ dp(i+1,j)$
 		+ $tmp=dp(i,j+2)\ or\ pre\ and\ dp(i+1,j)$
 	+ 否则，$tmp=dp(i+1,j+1)$
 	+ 更新$memo$，$memo[(i,j)]=tmp$
 	+ 返回$tmp$
 
 4. 返回$dp(0,0)$

### 复杂度分析
 - 时间复杂度：$O\left(P*S\right)$
 - 空间复杂度：$O(P*S)$

### Python

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        S=len(s)
        P=len(p)
        memo={}
        def dp(i,j):
            if((i,j) in memo):
                return memo[(i,j)]
            if(j==P):
                return i==S
            pre=i<S and p[j] in {s[i],"."}
            if(j<=P-2 and p[j+1]=="*"):
                tmp=dp(i,j+2) or pre and dp(i+1,j)
            else:
                tmp=pre and dp(i+1,j+1)
            memo[(i,j)]=tmp
            return tmp
        return dp(0,0)
```
![在这里插入图片描述](https://pic.leetcode-cn.com/efd7139ab5efb5054d358797f88afca00dc33cbd165a0ee27cb4711b005e0bf1.png)
