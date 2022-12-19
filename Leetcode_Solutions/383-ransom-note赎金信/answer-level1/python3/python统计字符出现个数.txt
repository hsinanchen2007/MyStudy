这种方法比较好理解 但是运行速度偏慢 就判断每个字符出现的次数，再把已经检查过的字符删去即可。

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        length = len(ransomNote)
        for i in ransomNote:
            if i in magazine and (ransomNote.count(i) <= magazine.count(i)):
                continue
                ransomNote.replace(i,'')
                magazine.replace(i,'')
            else:
                return False
        return True