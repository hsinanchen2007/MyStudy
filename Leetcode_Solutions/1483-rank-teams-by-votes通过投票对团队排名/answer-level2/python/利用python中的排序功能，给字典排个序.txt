```
class Solution(object):
    def rankTeams(self, votes):
        """
        :type votes: List[str]
        :rtype: str
        """
        dic={}
        #创建字典
        STR="ABCDEFGHIJKLMNOPQRSTUWVXYZ"
        for s in STR:
            dic[s]=[0]*26
        #统计票数
        for s in votes:
            for i in range(len(s)):
                dic[s[i]][i]+=1
        #排序
        dic=sorted(dic.items(),key=lambda x:(x[1],-ord(x[0])),reverse=True)
        res=''
        #组合输出结果
        for k,v in dic:
            if sum(v)>0:
                res+=k   
        return res
```
