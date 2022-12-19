### 解题思路
暴力判断字符
判断words 中的 字符串中的字符 是否在chars中存在，如果存在，则 将chars截取后再次判断

### 代码

```python
class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        num=0
        for word in words:
            s=chars
            len1=len(word)
            count=0
            for element in word:
                index=s.find(element)
                if index==0:
                    s=s[1:]
                if index>0 and index <len(s)-1:
                    s=s[0:index]+s[index+1:]
                if index==len(s)-1:
                    s=s[0:index]
                if (index==-1):
                    break
                count=count+1
            if (len1==count):
                num=num+len1
        return num
                

```