按回溯标签刷的题 先做的126 写了遍回溯 但是只能得到所有的序列 得不到最短的.. 看了这题的解析 改了一下用在这题上 但是ans和A的定义很愚蠢 为什么函数可以调用外面的数组不能调用变量？定义ans=2 函数加形参 返回的ans还是出错  求大神解答一下?
```
class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        wordList = set(wordList)
        if endWord not in wordList: return 0
        if beginWord in wordList: wordList.remove(beginWord)
        ans=[1,1]
        A=[1]
        m=len(beginWord)
        letters= set('qwertyuioplkjhgfdsazxcvbnm')
        def backtrack(forward,wordList):
            if not forward:
                A.remove(1)
                return
            cur=set()
            for word in forward:             
                for idx in range(m):
                    x,y = word[:idx],word[idx+1:]
                    for letter in letters:
                        temp = x + letter + y
                        if temp ==endWord: return len(ans)
                        if temp in wordList:                           
                            cur.add(temp)
                            wordList.remove(temp)
            ans.append(1)        
            backtrack(cur,wordList)
        backtrack({beginWord},wordList)
        if not A:
            return 0     
        return len(ans)
                    
```


