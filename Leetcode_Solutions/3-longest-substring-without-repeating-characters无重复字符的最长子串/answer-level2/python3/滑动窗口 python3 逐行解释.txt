# 题解


## 滑动窗口

 1. 初始化集合$memo$保存当前无重复字符的子串
 2. 初始化结果$max\_len=0$和当前子串的长度$cur\_len=0$，当前子串的左界索引$left=0$
 3. 遍历字符串，$i$，遍历区间$[0,n)$：
 	+ 增加当前字符，$cur\_len+=1$
 	+ 若当前字符已经出现在$memo$中，进入循环，保证$memo$中没有$nums[i]$：
 		+ 删除左界字符$nums[left]$，$left+=1$
 		+ 并将当前长度减一$cur\_len-=1$
 	+ 否则，将当前字符加入$memo$
 	+ 更新最大长度$max\_len=max(max\_len,cur\_len)$ 
 
 4. 返回$max\_len$

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(n)$
 - 空间复杂度：$O(n)$

### Python
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n=len(s)
        memo=set()
        res=0
        max_len=0
        cur_len=0
        left=0
        for i in range(n):
            cur_len+=1
            while(s[i] in memo):
                memo.remove(s[left])
                left+=1
                cur_len-=1
            memo.add(s[i])
            max_len=max(max_len,cur_len)
        return max_len
```