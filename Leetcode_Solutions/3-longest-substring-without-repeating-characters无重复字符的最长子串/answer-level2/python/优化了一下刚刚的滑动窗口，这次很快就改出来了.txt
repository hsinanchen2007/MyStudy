### 解题思路
我之前的问题是一定要到子串不能再加了才放进表里
完全可以走一步放一次
减少很多判断的时间
![image.png](https://pic.leetcode-cn.com/b707301727ca3cd06e7bcf29a38928b4d43189e87bbddbbe725c7370c2ae5bd1-image.png)


### 代码

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        if len(s)==0:return 0
        if len(s) == 1: return 1
        count={}
        left,right=0,1
        while right<len(s):
            if not s[right] in s[left:right]:
                count[s[left:right+1]]=len(s[left:right+1])
                right+=1
            else:
                left+=1
        return max(count.values())

```