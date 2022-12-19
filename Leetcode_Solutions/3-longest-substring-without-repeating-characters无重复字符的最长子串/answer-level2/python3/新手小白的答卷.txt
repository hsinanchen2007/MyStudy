### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        m=0  # 初始化maxlength的值
        l=[] # 初始化目前探索到的不重复的连续字符串
        for i in range(len(s)): # 在探索遍历之前
            if s[i] not in l: # 假如新加入的不重复，只需更新长度并和现在的最大值比较
                l.append(s[i])
                if len(l)>m:
                    m=len(l)
            else:
                l.append(s[i]) # 假如新加入的重复
                if len(l)>m:
                    m=len(l)-1 # 因为重复所以长度-1
                j=l.index(s[i])
                l=l[j+1:]       # 检测与新加入的重复的点，并保留后半段
        return m
```# 在时间上和内存消耗上都表现的不太好，在下今天初次尝试，欢迎大神点评