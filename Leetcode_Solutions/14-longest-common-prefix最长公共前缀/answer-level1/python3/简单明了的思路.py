解题思路如下：
1、因为是最长公共前缀，所以我们假设第一个就是最长的公共前缀prefix
2、把这个假设的prefix跟剩余的元素按顺序比对出新的prefix,再用这个新的prefix跟后面的元素继续比对
3、在跟每个字符串比对完后，判断prefix是否为空，即没有公共前缀了，后边的也不用继续比对，直接返回
代码如下
```
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0: return ''
        prefix = strs[0]
        for i in strs[1:]:
            while i[:len(prefix)] != prefix:
                prefix = prefix[:len(prefix)-1]
            if prefix == '':
                return prefix
        return prefix
```
