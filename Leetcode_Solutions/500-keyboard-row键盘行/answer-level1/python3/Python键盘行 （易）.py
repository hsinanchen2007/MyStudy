## 效率不咋地

![深度截图_选择区域_20190612223515.png](https://pic.leetcode-cn.com/7f7abd16bfc61669f2d94bcbc1b45c2ed6a25229bd5398c89b84f4da1709e673-%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_%E9%80%89%E6%8B%A9%E5%8C%BA%E5%9F%9F_20190612223515.png)

```
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        line1='qwertyuiop'
        line2='asdfghjkl'
        line3='zxcvbnm'
        
        i=0
        words_len = len(words)
        while i < words_len:
            word = words[i].lower()
            rm = False
            #以第一行为例,其余两个判断一样
            if word[0] in line1: #判断第一个在第几行
                for j in word[1:]: #判断剩下的
                    if j not in line1:  #有一个不符合，弹出这串字符，同时最大长度-1，删除标记
                        words.pop(i)
                        words_len-=1
                        rm=True
                        break
                if not rm: 
                    i+=1
                continue
            #
            if word[0] in line2:
                for j in word[1:]:
                    if j not in line2:
                        words.pop(i)
                        words_len-=1
                        rm=True
                        break
                if not rm:
                    i+=1
                continue
            #
            if word[0] in line3:
                for j in word[1:]:
                    if j not in line3:
                        print(j)
                        words.pop(i)
                        words_len-=1
                        rm=True
                        break
                if not rm:
                    i+=1
                continue
        return words
            
                
            
       
```

