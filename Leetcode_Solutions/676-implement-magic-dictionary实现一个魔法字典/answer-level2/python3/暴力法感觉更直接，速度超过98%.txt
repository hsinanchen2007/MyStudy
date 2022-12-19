直接把要找的字符串放进去挨个比较

代码块
class MagicDictionary:

    def __init__(self):
        self.dictionary = []

    def buildDict(self, dict) -> None:
        self.dictionary = self.dictionary + dict

    def search(self, word: str) -> bool:
        for i in range(len(self.dictionary)):
            if word == self.dictionary[i]:      #相等就跳过
                continue
            if len(self.dictionary[i]) != len(word): #长度不等也跳过
                continue
            else:
                count = 0
                for j in range(len(self.dictionary[i])):
                    if self.dictionary[i][j] != word[j]:
                        count = count + 1
                    if count > 1:         #不相等字母大于2也跳过
                        break
                if count == 1:
                    return True
        return False
