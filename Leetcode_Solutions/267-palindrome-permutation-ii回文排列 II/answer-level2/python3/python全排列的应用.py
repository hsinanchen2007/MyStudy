```
class Solution:
    def generatePalindromes(self, s: str):
        from collections import Counter
        dic = Counter(s)
        num_1=0
        str_1=''
        tmp=''
        if dic.__len__()==1:
            return [s]
        for key in dic.keys():
            if dic[key]==1:
                num_1+=1
                str_1=key
                if num_1==2:
                    return []
            elif dic[key]%2!=0:
                num_1+=1
                str_1=key
                dic[key]-=1
                if num_1==2:
                    return []
            if dic[key]%2==0:
                dic[key]=dic[key]//2
                tmp+=dic[key]*key
        import itertools
        tmp_list=list(tmp)
        rs=set()
        for i in itertools.permutations(tmp_list,tmp_list.__len__()):
            rs.add(''.join(i)+str_1+''.join(i[::-1]))
        return list(rs)
```
