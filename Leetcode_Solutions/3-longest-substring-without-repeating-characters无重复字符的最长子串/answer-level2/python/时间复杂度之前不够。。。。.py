### 解题思路
这道题写过两次代码，第一次自己写的，时间复杂度不够，暴力求解：
第一次代码如下：思路为
1.获取字符串所有子串。
2.记录子串中的字母在子串中出现的次数。
3.再用列表比较。
4.获取列表max
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        if len(s)==0:
            return 0
        else:
            l3=[]
            l4=[]
            for x  in range(len(s)):
                for y in range(len(s)-x):
                    # print(s[x:x+y+1])
                    l=[]
                    l2=["1"]
                    for   z in (s[x:x+y+1]):
                        l.append(str(s[x:x+y+1].count(z)))
                    if l==l2*len(l):
                    	l3.append(len(s[x:x+y+1]))
            return max(l3)

### 代码
这个主要是采用窗口滑动，就向滑动条一样，遇到障碍物再处理。
```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
    	cur_len=0
    	max_len=0
    	win=[]
    	for x in s:
    		if x  not  in win :
    			win.append(x)
    			cur_len+=1
    		else :
    			c=win.index(x)
    			win=win[c+1:]
    			win.append(x)
    			cur_len=len(win)
    		if cur_len>max_len:max_len=cur_len
    	return max_len
```