### 解题思路
1.创建哈希表，结构为：第n行的字符：n，以此来查询所求单词的各个字符在第几行
2.遍历列表words,再遍历每个单词的各个字符，看是否是同一行，我这里设置了一个flag,如果遇到不是同一行的，就设Flag为False
3.最后根据Flag的值来判断单词是否符合要求

### 代码

```python3
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        dct={}
        for i in 'qwertyuiopQWERTYUIOP': #第一行
            dct[i]=1
        for i in 'asdfghjklASDFGHJKL':  #第二行
            dct[i]=2
        for i in 'zxcvbnmZXCVBNM':      #第三行
            dct[i]=3
        ans=[]                          #目标数组
        for word in words:          #遍历单词表 
            flag=True              #初值设为True，如果最后也是True，说明这个单词的所有字符都是一行
            for chr in word:        #遍历字符
                if dct[chr]!=dct[word[0]]:  #以第一个字符的行数为准，遇到不同行直接判否
                    flag=False
                    break
            if flag:            #遍历结束仍然True,则添加进结果
                ans.append(word)
        return ans  #返回目标数组
                
```