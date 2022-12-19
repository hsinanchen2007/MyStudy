![31{9QL01)1X@UN9PVGB0AMS.png](https://pic.leetcode-cn.com/542b2167dc08a91d216d0556157477e05f04833e04a535a4fcd1dc67889d8383-31%7B9QL01\)1X@UN9PVGB0AMS.png)
#代码浅显易懂,就是用字符串的长度作为字典的键,遇到通配符的时候跳过这个字母的匹配
class WordDictionary:
    def __init__(self):
        self.d = {}
        
    def addWord(self, word: str) -> None:
        t = len(word)
        if len(word) in self.d:
            self.d[t] += [word]
        else:
            self.d[t] = [word]

    def search(self, word: str) -> bool:
        l_word = len(word)
        try:
            for i in self.d[l_word]:
                count = 0
                for ii in range(l_word):
                    if i[ii] == word[ii] or word[ii] == '.':
                        count +=1
                    else:
                        break
                if count == l_word:
                    return True
        except:
            return False
        return False