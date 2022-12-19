### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s):
        start = 0  ##记录不重复字符串开始位置
        maxLength = 0 ##最大长度
        count = {} ##利用字典存储字符串s中字符的index
        l = len(s) ##字符串的总长度
        i = 0
        while True:
            if i - start > maxLength: ##判断浮标位置与start位置的距离，如果大于maxlength，记录在maxlength
                maxLength = i - start
            if i >= l:
                break
            temp = count.get(s[i])
            if temp == None or temp < start:##在字典中查找该字符如不存在或者在start位置之前，更新该字符在字典中的信息为当前索引
                count[s[i]] = i
            else:
                start = count[s[i]] + 1 ##在字典中查找该字符存在并且在start位置之后，说明当前子字符串中存在重复字符，更新start值重复字符串位置之后的一个位置
                count[s[i]] = i
            i += 1
        return maxLength
```