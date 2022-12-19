### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        dic={1:"I",5:"V",10:"X",50:"L",100:"C",500:"D",1000:"M",4:"IV",9:"IX",40:"XL",90:"XC",400:"CD"
        ,900:"CM"}
        key=dic.keys()
        values=dic.values()
        #print(key,values)
        out_str=""
        answer=num

        while (answer>0):
             key=list(key)
             max_num=max(key)
             c=answer//max_num
             if c>0 :
                 answer=answer-max_num
                 out_str=out_str+dic[max_num]
                #print(out_str)
             else:
                key.remove(max_num)
        return out_str
```