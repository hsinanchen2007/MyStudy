### 解题思路

1、主逻辑

    从第一个单词开始遍历
        如果该单词不可以放入队列中（超过maxwidth），则消费掉队列中数据（按两端对齐方式）
        如果该单词可以放入队列中， 则放入队列中
    将队列中数据消费（按最后一行消费）

2、两端对齐方式消费

    如果只有一个单词，则直接后段补空格
    计算空格的基本间距和剩余间距

    消费第1个单词
    从第2个单词开始消费第i单词
        先补上基本间距
        再补上剩余间距（如果剩余间距大于0，则补一个空格，剩余间距减1）
        再补上第i个单词

3、按最后一行消费

    消费第1个单词
    从第2个单词开始消费第i单词
        先补空格
        再补上第i单词
    最后补足空格

### 代码

```python
class Solution(object):
    def catWords(self, words, maxWidth):
        if len(words)==1:
            return words[0] + ''.join([' ']*(maxWidth-len(words[0])))
            
        empty = maxWidth;
        for i in range(0, len(words)):
            empty -= len(words[i])
        baseEmpty,remainEmpty = empty/(len(words)-1), empty % (len(words)-1)

        res = words[0]
        for i in range(1,len(words)):
            res += ''.join([' ']*baseEmpty)
            if remainEmpty>0:
                res+= ' '
                remainEmpty = remainEmpty - 1
            res = res + words[i]
        return res

    def catLastLine(self, words, maxWidth):
        res  = words[0]
        for i in range(1, len(words)):
            res += (' '+ words[i])
        return res + ''.join([' ']*(maxWidth-len(res)))

    def fullJustify(self, words, maxWidth):
        res, lineWords, n = [], [], 0
        for i in range(0, len(words)):
            if n + len(words[i]) > maxWidth:
                res.append(self.catWords(lineWords, maxWidth))
                lineWords = []
                n = 0
            lineWords.append(words[i])
            n = n + len(words[i]) + 1
        res.append(self.catLastLine(lineWords, maxWidth))
        return res
```