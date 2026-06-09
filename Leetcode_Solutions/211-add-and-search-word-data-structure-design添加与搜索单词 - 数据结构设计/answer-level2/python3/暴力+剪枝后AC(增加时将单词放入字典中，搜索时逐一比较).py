![图片.png](https://pic.leetcode-cn.com/806fe6e6654fb3e99b1f9919b5e4d25d5744f3043e05bce3dcc36b98067046f2-%E5%9B%BE%E7%89%87.png)
1.碰到增加单词时，逐一的将单词放入哈希表temp中即可

2.搜索单词时，对hash表中的每一个单词进行比对，长度不同的直接跳过到下一个单词，碰见长度相同的，则对两个单词中的字符逐一比对。

        1.如果预见万能字符'.'，则continue比对下一个字符。

        2.如果碰见字符不匹配，直接break

如果找到了匹配的单词，则置标识符s为1，这样就能停止外层搜索实现剪枝。




AC代码如下
```python []
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.temp={} #temp用于存放用户添加的单词
        self.statu=0 #statu为标识位，为0代表正在插入，为1代表正在搜索，作用是实现剪枝
        self.last='' #last记录了用户上一次搜索的单词
        self.r=True  #r用来记录上一次搜索的结果

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        self.temp[word]=1 #直接向hash表插入单词即可
        self.statu=0 #statu置0，代表正在插入

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        if self.statu==1 and self.last==word: #如果当前正在搜索，并且正在搜索的词和上次搜索的词相同，直接返回上次的结果
            return self.r
        s=0
        for x in self.temp: #对temp中的单词逐一匹配
            if s==1: #如果搜索到了单词，则直接break掉
                break
            if len(x)!=len(word): #长度不等直接continue
                continue
            for i in range(len(x)):
                if word[i]=='.':
                    if i==len(x)-1:
                        s=1
                    continue
                if word[i]!=x[i]:
                    break
                if i==len(x)-1: 
                    s=1
        self.statu=1 #代表正在搜索
        self.last=word #记录上一次的单词
        if s==0:
            self.r=False
        else:
            self.r=True
        return True if s==1 else False


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
```

