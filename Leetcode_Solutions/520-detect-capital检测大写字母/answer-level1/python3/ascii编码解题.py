class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        # 大写字母的ascii码是65-90
        # 小写字母的ascii码是97-122
        # ord() 可以将 字符转换成ascii编码
        if len(word) == 1:
            return True
        if ord(word[0])<97 :
            if ord(word[1]) < 97:
                for i in word[2:]:
                    if ord(i)>=97:
                        return False
                return True
            else:
                for i in word[2:]:
                    if ord(i)<97:
                        return False
        
                return True
        for i in word:
            if ord(i)<91:
                return False
        return True
            