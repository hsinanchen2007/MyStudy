```
class Solution:
    def maximumSwap(self, num: int) -> int:
        if num<=9:
            return num
        
        num_list=list(str(num))
        rs=num
        for i in range(num_list.__len__()):
            for j in range(i+1,num_list.__len__()):
                tmp_list=num_list[::]
                tmp=tmp_list[i]
                tmp_list[i]=tmp_list[j]
                tmp_list[j]=tmp
                tmp_num=int(''.join(tmp_list))
                if rs<tmp_num:
                    rs=tmp_num
        return rs
```
