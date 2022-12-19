class Solution:
    def permutation(self, string: str) -> List[str]:

        if len(string)==1:
            res=[]
            res.append(string)
            return res
        else:
            tempstr=string[0]
            temp=[]
            temp.append(tempstr)
            for i in range(1,len(string)):
                ch=string[i]
                res=[]
                for j in temp:
                    res.extend(self.strinsert(j,ch))
                temp=res
            return temp
    def strinsert(self,string,ch):
        res=[]
        for i in range(len(string)):
            res.append(string[0:i]+ch+string[i:len(string)])
        res.append(string+ch)
        return res