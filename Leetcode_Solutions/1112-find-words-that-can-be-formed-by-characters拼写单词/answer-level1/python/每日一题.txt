### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words, chars) -> int:
        count = 0
        for word in words:
            tmp = chars
            signal = 0
            for i in range(len(word)):
                if word[i] in tmp:
                    ##replace 需要用一个新变量保存 原来的变量没有删除
                    tmp = tmp.replace(word[i],'',1)
                else:
                    signal = 1
                    break
            if not signal:
                count += len(word)
        return count
```