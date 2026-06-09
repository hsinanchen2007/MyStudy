### 解题思路
利用HASH表
#### 1.将chars中的每个字母保存到一个HASH表中,(可以使用Counter)
如：chars="hash",==> refer={'h':2,'a':1,'s':1}
#### 2.对words中的每个单词word处理：word中的每个字母保存至HASH表
如word="ha",==> count={'h':1,'a':1}
对比refer和count中的每个字母，若count中的字母对应的个数大于refer中的，说明这个word不存在于chars中。通过设置标志位is_word判断这个单词符不符合要求。

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        from collections import Counter
        res=0
        refer=Counter(chars)#计算chars中每个字母的数目
        for word in words:#对每个单词,
            count=Counter(word)#进行计算它的字母数目
            #if all([count[i]<=refer[i] for i in count]):res+=len(word)
            is_word=True
            for letter in count:
                if count[letter]>refer[letter]:
                    is_word=False
                    break
            if is_word==True:
                res+=len(word)
        return res
            
            
            

```