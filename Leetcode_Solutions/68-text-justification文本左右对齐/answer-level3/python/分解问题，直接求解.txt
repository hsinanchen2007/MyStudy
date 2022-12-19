### 解法一：分解问题求解
这题理顺逻辑，将问题分解成小块来解决就可以
题目要求做两件事情：
1.贪心地查找每一行尽可能多的词汇
2.将这些词汇按照要求用空格连接成一个字符串
分别按照要求实现这两个问题即可，需要特别考虑最后一行句子的组成情况

### 代码

```python
class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        #根据给定数字和宽度生成字符串,输入词汇、词总长度、词汇总数
        def wordTostr(words,total_len,count,maxWidth):
            if count>1:
                div=(maxWidth-total_len)/(count-1)
                mod=(maxWidth-total_len)%(count-1)
                res=""
                for i in range(count):
                    res+=words[i]
                    if i<count-1:
                        if i<mod:
                            res+=" "*(div+1)
                        else:
                            res+=" "*div
            else:
                res=words[0]+" "*(maxWidth-total_len)
            return res

        #贪心法找出每一行的词，生成字符串
        n=len(words)
        res=[]
        start_ind=0
        total_len=0
        count=0
        for i in range(n):
            w_l=len(words[i])
            if maxWidth-total_len-count-w_l>=0:
                if i==n-1:
                    s=""
                    for w in words[start_ind:n-1]:
                        s+=w
                        s+=" "
                    s+=words[n-1]
                    s+=" "*(maxWidth-total_len-count-w_l)
                    res.append(s)
                else:
                    if count==0:
                        start_ind=i
                    total_len+=w_l
                    count+=1
            else:
                if i==n-1:
                    res.append(wordTostr(words[start_ind:i],total_len,count,maxWidth))
                    res.append(words[n-1]+" "*(maxWidth-w_l))
                else:
                    res.append(wordTostr(words[start_ind:i],total_len,count,maxWidth))
                    start_ind=i
                    count=1
                    total_len=w_l
        return res
                    
```