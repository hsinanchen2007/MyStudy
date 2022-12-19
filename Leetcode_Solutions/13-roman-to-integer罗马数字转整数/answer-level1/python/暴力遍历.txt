先将字符串转成列表，然后先判定两字符的，再判断一个字符的，这样想法比较简单，容易实现


```python []
class Solution:
    def romanToInt(self, s: str) -> int:
        roman=['I','V','X','L','C','D','M','IV','IX','XL','XC','CD','CM']
        num =[1,5,10,50,100,500,1000,4,9,40,90,400,900]
        s_list = list(s)
        num_return = 0
        
        while (len(s_list)!=0):
            if len(s_list)==1:
                num_return = num_return+num[roman.index(s_list[0])]
                del s_list[0]
                continue
            a = s_list[0]+s_list[1]
            if(a in roman):
                num_return = num_return+num[roman.index(a)]
                del s_list[0]
                del s_list[0]
            else:
                a = s_list[0]
                num_return = num_return+num[roman.index(a)]
                del s_list[0]
        return num_return
```

