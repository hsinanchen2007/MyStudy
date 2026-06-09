解法一：依次判断索引和分别为0,1,2,...的情形是否有解，若有解，则返回其值。
```
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        res=[]
        len1=len(list1)
        len2=len(list2)
        for i in range(len1+len2-1):
            for j in range(min(len1,i+1)):
                if i-j<len2 and list1[j]==list2[i-j]:
                    res.append(list1[j])
            if res:
                return res
```
解法二：哈希表
```
class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        res=[]
        dic={}
        sume = len(list1)+len(list2)
        for i,ele in enumerate(list1):
            dic[ele]=i
        for j,e in enumerate(list2):
            if dic.get(e)!=None:
                if dic.get(e)+j<sume:
                    sume = dic.get(e)+j
                    res=[e]
                elif dic.get(e)+j==sume:
                    res.append(e)
        return res
```
