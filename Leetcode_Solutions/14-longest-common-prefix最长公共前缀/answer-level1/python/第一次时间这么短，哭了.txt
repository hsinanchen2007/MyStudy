### 解题思路
头一次时间这么短嘤嘤嘤，实在是太菜了。想的是把字母都存到一个set里，如果set长度大于1了就说明已经找到最长的前缀了，输出即可。

### 代码

```python
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if(strs == []):
            return ""

        num = len(strs[0])
        for s in strs:
            length = len(s)
            if(length < num):
                num = length
            
        test = set()
        addone = ''
        final = ''

        for i in range(num):
            for s in strs:
                test.add(s[i])
                addone = s[i]
            
            if(len(test) > 1):
                break
            
            test.remove(addone)
            final += addone
        
        return final

```