```
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        #定义一个临时列表
        tmp=[]
        for i in range(len(strs)):
            l1=sorted(strs[i])
            tmp.append("".join(l1))
        dic={}
        result=[]
        #定义输出列表的维数
        dim=0
        for i in range(len(strs)):
            if tmp[i] not in dic:
                dic[tmp[i]]=dim
                result.append([strs[i]])
                dim+=1
            else:
                result[dic[tmp[i]]].append(strs[i])
        return result
```
