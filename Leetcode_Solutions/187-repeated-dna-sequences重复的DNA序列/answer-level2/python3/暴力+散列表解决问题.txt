1.首先利用切片的方法获得所有长度10的列表
2.利用散列表统计个数，然后遍历列表将符合条件的挑出
```
class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        str_list=[]
        for i in range (len(s)):
            str_list.append(s[i:i+10])
        p={}
        for j in str_list:
            p[j]=p.get(j,0)+1
        new_list=[]
        for k,v in p.items():
            if v>1:
                new_list.append(k)
        return new_list
```
