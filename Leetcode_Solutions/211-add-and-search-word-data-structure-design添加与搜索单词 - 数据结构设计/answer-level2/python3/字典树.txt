![image.png](https://pic.leetcode-cn.com/6d7bbf60ee7e29ea3fc297250a31eb3fe2fe973a45d9c9495da3f976c2e3829b-image.png)
class WordDictionary(object):

    def __init__(self):
        self.root={}

    def addWord(self, word):
        t=self.root
        for i in word:
            if i not in t:
                t[i]={}
            t=t[i]
        t["end"]={}

    def search(self, word):
        t=self.root
        def f(t,word):
            for i,j in enumerate(word):
                if j == '.':            #通配符
                    T=False
                    for m in t:
                        T=T or f(t[m],word[i+1:])
                    return T
                elif j in t:
                    t=t[j]
                else:
                    return False
            return True if "end" in t else False
        return f(t,word)