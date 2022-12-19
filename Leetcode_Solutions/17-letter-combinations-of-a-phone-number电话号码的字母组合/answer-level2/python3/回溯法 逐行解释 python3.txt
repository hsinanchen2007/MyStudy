# 题解
第一时间想到回溯，因为这种找全部的解，常规都是使用回溯
## 回溯

 1. 初始化词典$phone=\{"2":["a","b","c"],\cdots\}$，初始化$res=[]$
 2. 特判，若字符串为空，返回$[]$
 3. 定义回溯函数$helper(s,tmp)$：$s$表示待匹配的字符串，$tmp$表示之前匹配的结果
 	+ 若$s==""$：表示匹配完毕，此时将$tmp$加入$res$，并返回
 	+ 遍历$s[0]$对应的所有可能的字母$c$：
 		+ 执行$helper(s[i+1,...],tmp+c)$
 
 4. 执行$helper(digits,"")$
 5. 返回$res$

 

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(3^{N}*4^{M})$，其中 N 是输入数字中对应 3 个字母的数目（比方说 2，3，4，5，6，8）， M 是输入数字中对应 4 个字母的数目（比方说 7，9），N+M 是输入数字的总数
 - 空间复杂度：$O(3^{N}*4^{M})$

### Python
```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        phone = {'2': ['a', 'b', 'c'],
                 '3': ['d', 'e', 'f'],
                 '4': ['g', 'h', 'i'],
                 '5': ['j', 'k', 'l'],
                 '6': ['m', 'n', 'o'],
                 '7': ['p', 'q', 'r', 's'],
                 '8': ['t', 'u', 'v'],
                 '9': ['w', 'x', 'y', 'z']}
        if(not digits):
            return []
        res=[]
        def helper(s,tmp):
            if(s==""):
                res.append(tmp)
                return
            for c in phone[s[0]]:
                helper(s[1:],tmp+c)
        helper(digits,"")
        return res
```