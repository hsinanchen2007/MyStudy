### 解题思路
#### 1.分类器设置
采用三个HASH TABLE ,key分别 存放原来的单词（用以比较是否有错）、转换为小写的单词（用以确认错误是否由大小写差异引起）、转换为通配符的单词（用以确认错误是否由元音引起），值为原来的单词（用于返回匹配的单词）。
#### 2.单词匹配
对queries的每个单词进行判断：无错否？-->大小写有错否？-->元音有错否？
##### PS.注意优先级的设定，需要判定单词的是否已存在于HASH表中，若存在，则舍弃；只在HASH表中保存最先发现的单词。

### 代码

```python3
class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        #HASH Table--分类处理
        refer_ori=set(wordlist)#无措的集合，直接把单词放到集合中
        refer_lower={}#大小写有错的HASH_TABLE（都转换为小写）
        refer_sta={}#元音有错的HASH_TABLE（对元音使用通佩符*）
        res=[]#保存结果
        for word in wordlist:#对于参考列表中的每个单词，要考虑匹配的优先级
            #添加大小写有错的HASH_TABLE
            wordlow=word.lower()
            if wordlow not in refer_lower:#如果wordlow原来不存在于字典中，
                refer_lower[wordlow]=word#将其添加至字典。保证优先级，如Here,here，只添加最先扫描到的Here，满足优先级
            #添加元音有错的HASH_TABLE
            wordsta=''.join("*" if c in "aeiou" else c for c in wordlow)
            if wordsta not in refer_sta:#如果wordsta原来不存在于字典中，
                refer_sta[wordsta]= word#将其添加至词典。保证优先级，如h*r*对应Here,here,只添加最先扫描到的Here，满足优先级
        for word in queries:#对queries的每个单词进行判断：无错否？-->大小写有错否？-->元音有错否？
            #无错否？
            if word in refer_ori:
                res.append(word)
                continue
            #大小写有错否？
            wordL=word.lower()
            if wordL in refer_lower:
                res.append(refer_lower[wordL])
                continue
            #元音有错否？
            wordS=''.join('*' if c in "aeiou" else c for c in wordL)
            if wordS in refer_sta:
                res.append(refer_sta[wordS])
                continue
            else:#无法匹配返回""
                res.append("")
        return res

                
                


```