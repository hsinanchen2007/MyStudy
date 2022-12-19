### 解题思路
本题，本小白最开始解法非常复杂，后看一位大神说法，发现新大陆
这个里面首先需要考虑一个长度问题，每个字符串的长度不一定相等。如果用for+len会非常麻烦。
大神给出了用zip函数来解决这个问题，zip函数有两种形式：zip()和zip(*),前者为压缩，后者为解压缩。
如果给出的一个str=['asdg','adfer','sda'],在zip[*str]后，得到的结果为[[a,a,a],[s,d,d],[d,f,a]]。
这就解决了字符串长度不一致的问题。
set这个函数比较复杂，可以简单的理解为它可以把一个列表里所有重复的全部删掉

### 代码

```python
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        s= ''
        for i in zip(*strs):
            if len(set(i))==1:
                s = s + i[0]
            else:
                break
        return s
     
```