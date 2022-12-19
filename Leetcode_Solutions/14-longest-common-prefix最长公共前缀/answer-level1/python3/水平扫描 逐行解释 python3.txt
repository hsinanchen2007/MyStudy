## 水平扫描
想法：
取字符串数组中的第一个字符串为$res$，逐个和剩下的字符串比较并更新$res$

 1. 特判，若字符串数组为空，返回$""$，或只有一个字符串，返回$strs[0]$，$res=strs[0]$
 2. 遍历字符串数组，$i$，遍历区间$[1,len(strs))$
 	+ 若$res=""$或$strs[i]==""$，返回$""$
 	+ 定义$min\_len=min(len(res),len(strs))$，当前公共前缀$tmp=""$
 	+ 比较两个字符，遍历区间$j\in[0,min\_len)$
 		+ 若$res[j]==strs[i][j]$，$tmp+=res[j]$
 		+ 否则，跳出
 	+ 更新$res$
 
 3. 返回$res$

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
### 复杂度分析
 - 时间复杂度：$O(S)$，$S$为字符串数组中字符数之和
 - 空间复杂度：$O(1)$

### Python
```python
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if(not strs):
            return ""
        if(len(strs)<2):
            return strs[0]
        res=strs[0]
        for i in range(1,len(strs)):
            if(len(strs[i])==0 or len(res)==0):
                return ""
            min_len=min(len(res),len(strs[i]))
            tmp=""
            for j in range(min_len):
                if(res[j]==strs[i][j]):
                    tmp+=res[j]
                else:
                    break
            res=tmp
        return res
```
另外一种Pythonic的写法：
```python
class Solution:
    def longestCommonPrefix(self, s: List[str]) -> str:
        if not s:
            return ""
        res = s[0]
        i = 1
        while i < len(s):
            while s[i].find(res) != 0:
                res = res[0:len(res)-1]
            i += 1
        return res


```
## Pythonic的解法
利用$zip$拆包，
比较每个字符串的相同位置。
具体可以搜索

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
### 复杂度分析
 - 时间复杂度：$O(S)$，$S$为字符串数组中字符数之和
 - 空间复杂度：$O(1)$

### Python
```python
class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        res = ""
        for tmp in zip(*strs):
            tmp_set = set(tmp)
            if len(tmp_set) == 1:
                res += tmp[0]
            else:
                break
        return res

```
