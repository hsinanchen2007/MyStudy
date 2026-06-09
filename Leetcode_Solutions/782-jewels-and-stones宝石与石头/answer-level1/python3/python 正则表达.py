class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        a = '[' + str(J) + ']'
        b = str(S)
        numRegex = re.compile(a)
       
        return len( numRegex.findall(b))

模式匹配正则表达，建立自己的字符分类