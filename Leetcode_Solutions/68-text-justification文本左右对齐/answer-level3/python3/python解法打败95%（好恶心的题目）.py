本题虽然是困难题，但我认为困难的在于细节，思路如下：
1. 先根据规则将每一行的单词存入列表
2. 根据列表单词的数量放置空格：单词数为1和2时都比较简单，当单词数大于2时做额外处理（详情见代码）
3. 最后处理最后一行，也比较简单


```
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        res=[]
        l=0
        s=[]
        #先将单词保存
        for i in range(len(words)):
            if l+len(words[i])<=maxWidth:
                l=l+len(words[i])+1
                s.append(words[i]) 
            else:
                res.append(s)
                l=len(words[i])+1
                s=[words[i]]
        res.append(s)
        
        #根据单词放空格
        ans=[]
        for word in res[:-1]:
            if len(word)==1:
                ans.append(word[0]+' '*(maxWidth-len(word[0])))
            elif len(word)==2:
                ans.append(word[0]+' '*(maxWidth-len(word[0])-len(word[1]))+word[1])
            else:#单词数大于2时                             
                sum1=sum([len(i) for i in word])

                m = (maxWidth-sum1)//(len(word)-1)
                n = (maxWidth-sum1) - m*(len(word)-1)

                a=word[0]
                i=1
                while i<len(word):
                    if n>0:
                        a=a+' '*(m+1)+word[i]
                    else:
                        a=a+' '*m+word[i]
                    i+=1
                    n-=1
                ans.append(a)
        #处理最后一行
        b=res[-1][0]
        i=1
        while i<len(res[-1]):
            b=b+' '+res[-1][i]
            i+=1
        b+=(maxWidth-len(b))*' '
        ans.append(b)
        
        return ans
```
