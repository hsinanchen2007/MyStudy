1. 首先求取words数组中每个单词的长度，用于后续排列；
2. 求每行最多可以放置多少个单词，每个单词间先放一个空格，并形成如下初步结果：["Science is what we","understand well","enough to explain to","a computer. Art is","everything else we","do"]
3. 对初步结果进行空格处理，将maxWidth中的剩余空格数量，插入每组字符串中正确位置，返回结果。

```
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        words_length = [len(i) for i in words]
        l = len(words)
        if l == 0:return [' '*maxWidth]
        
        #将句子按照maxWidth正确分组，存入res
        #如下格式["Science is what we","understand well","enough to explain to","a computer. Art is","everything else we","do"]
        res = [words[0]]
        res_length = maxWidth - (words_length[0]+1)
        for i in range(1, l):
            if res_length >= words_length[i]:
                res_length -= (words_length[i]+1)
                res[-1] += ' ' + words[i]
            else:
                res.append(words[i])
                res_length = maxWidth - (words_length[i]+1)
        
        #处理每组中的空格，最后一行另行处理
        for i,j in enumerate(res):
            if len(j) < maxWidth and i < len(res)-1:
                blank = maxWidth - len(j)
                temp = j.split(' ')
                if len(temp) == 1:
                    res[i] = temp[0] + ' '*(maxWidth - len(j))
                else:
                   #将空格插入合适位置，必须简化，否则超时
                    count = blank // (len(temp) - 1)
                    blank %= (len(temp) - 1)
                    for p in range(1, len(temp)):
                        if blank > 0:
                            temp[p] = ' '*(count + 1) + temp[p]
                            blank -= 1
                        else:
                             temp[p] = ' '*count + temp[p]
                    res[i] = ' '.join(temp)
        
        #处理最后一行
        res[-1] += ' '*(maxWidth - len(res[-1]))
        
        return res

执行结果：通过显示详情
执行用时 :36 ms, 在所有 python3 提交中击败了95.74%的用户
内存消耗 :13.8 MB, 在所有 python3 提交中击败了6.82%的用户
```
