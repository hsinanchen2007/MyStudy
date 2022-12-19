### 解题思路
利用字典统计每个不同字符出现次数，奇数个-1，偶数个全部接受。最后根据奇数是否出现确认返回值，出现过则从这些出现次数为奇数的字符中选一个作为回文数中间字符即可。萌新解题，不喜勿喷，有优化解法欢迎评论交流，谢谢。

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
    	ans={}
    	count=0
    	odd=0
    	for a in s:
    		ans[a]=ans.get(a,0)+1
    	if len(ans)==1:
    		k,v=ans.popitem()
    		return v
    	else:
    		for val in ans.values():
    			if val %2==0:
    				count+=val
    			else:
    				count+=val-1
    				odd+=1
    		if odd:
    			return count+1
    		else:
    			return count
```