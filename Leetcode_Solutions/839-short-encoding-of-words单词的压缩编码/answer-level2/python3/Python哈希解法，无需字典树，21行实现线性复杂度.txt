其实不需要字典树也可以：  
只要把每个单词的所有后缀存起来即可，其中如果后缀是一个完整的单词比较特殊  
比如：time的后缀有 `e, me, ime, time` .  
字典：`wmap: {'e' : 1, 'me' : 1, 'ime' : 1, 'time' : 2 }`  
然后判断逻辑就是
- 1. 目前这个单词的后缀是否以前出现过
- 若出现过，判断该后缀是否为以前的完整的单词`wmap[wi[-j:]]`，即现在的后缀以前出现过这样的单词，是则减去  
`例如：[me, time]`
- 若出现过，判断该后缀是否是现在的完整的单词 `j==len(wi)`，即现在的单词以前出现过，是则减去  
`例如：[time, me]`
- 若没出现过，则在字典中存下为1  
时间复杂度：$ O(\sum{w_i}) $ ，其中 $ w_i $ 是 words[i] 的长度。对于每个单词中的每个字母，只需要进行常数次操作。  
```python 
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        lenw = len(words)
        cnt_len=lenw
        wmap = dict()
        for i,wi in enumerate(words):
            cnt_len+=len(wi)
            for j in range(1,len(wi)+1):
                try:
                    wmap[wi[-j:]]
                except:
                    if(j==len(wi)):
                        wmap[wi]=2
                    else:
                        wmap[wi[-j:]]=1
                else:
                    if j==len(wi) or wmap[wi[-j:]]==2:
                        wmap[wi[-j:]]=1
                        cnt_len-=1
                        cnt_len-=j
        return cnt_len
```
