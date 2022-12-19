### 解题思路
看注释

### 代码

```python3
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:

        ret = []
        # 当前行可以放的单词
        curArr = []
        # 当前单词总长度，不包括空格
        curLen = 0
        # 单词间预留一个空格位置
        baseSpaceCount = 0
        
        for word in words:
            # 如果已存的单词 + 这个单词 + 所需空格没超过一行长度，就放进去
            if len(word) + curLen + baseSpaceCount<= maxWidth:
                curArr.append(word)
                curLen += len(word)
                baseSpaceCount += 1
            else:
            # 需要换行，把保存的词语拼接成句子
                spaceCount = maxWidth - curLen
                # 词间空格数
                spacePer = 0
                # 多出来的空格数
                extraSpace = 0
                if len(curArr) > 1:
                    spacePer = spaceCount // (len(curArr) - 1)
                    extraSpace = spaceCount - spacePer * (len(curArr) - 1)
                needAddSpaceCount =  len(curArr) - 1
                lineStr = ""
                for wo in curArr:
                    lineStr += wo
                    if needAddSpaceCount > 0:
                        needAddSpaceCount -= 1
                        lineStr += " " * spacePer
                    if extraSpace > 0:
                        lineStr += " "
                        extraSpace -= 1
                if len(lineStr) < maxWidth:
                    lineStr += " " * (maxWidth - len(lineStr))
                ret.append(lineStr)

                curArr = [word]
                curLen = len(word)
                baseSpaceCount = 1
        
        # 处理最后一行
        spaceCount = maxWidth - curLen
        lineStr = ""
        for wo in curArr:
            lineStr += wo + " "
        
        if len(lineStr) > maxWidth:
            lineStr = lineStr[0:maxWidth]
        elif len(lineStr) < maxWidth:
            lineStr += " " * (maxWidth - len(lineStr))
        ret.append(lineStr)
        return ret
```