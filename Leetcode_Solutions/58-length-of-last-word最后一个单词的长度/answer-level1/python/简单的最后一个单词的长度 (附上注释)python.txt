```
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 仅包含大小写字母和空格 ' ' 的字符串
        # 返回其最后一个单词的长度
        # 不存在最后一个单词 直接返回0
        if len(s)==0:
            return 0
        j=0
        for i in range(len(s)-1,-1,-1):
            # 找到不是空格
            if s[i]!=' ':
                j+=1
            # 找到空格 
            else:
                # 再判断有无字母 有的话证明已经找到了最后一个单词 j为其长度
                if j!=0:
                    return j
        # 遍历结束也没有return
        # 说明在找到字母之后再也没找到空格 即只有一个单词 j为其长度
        return j
```
