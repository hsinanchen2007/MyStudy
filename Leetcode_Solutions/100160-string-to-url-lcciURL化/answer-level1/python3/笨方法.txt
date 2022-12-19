# 标题
# 1.先遍历查出字母数量
# 2.要添加%S就是长度减去字母数量
# 3.replace替换即可

class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        count =0
        for i in range(len(S)):
            if S[i] !=" ":
                count = count+1
        l=length-count
        s1= S.replace(" ","%20",l)
        return s1.replace(" ","")