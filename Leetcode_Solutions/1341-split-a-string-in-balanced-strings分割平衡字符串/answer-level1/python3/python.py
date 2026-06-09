```
代码块class Solution:
    def balancedStringSplit(self, s: str) -> int:
        l_list=[]
        r_list=[]
        c=0
        for i in s:
            if i == 'L':
                l_list.append(i)
            else:
                r_list.append(i)
            if len(l_list) == len(r_list):
                c+=1
                l_list.clear()
                r_list.clear()
        return c
```
第一次写就成功了，没想到用时还挺快的。