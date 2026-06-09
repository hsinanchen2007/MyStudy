### 解题思路
蒟蒻递归写法，望dalao轻喷
### 代码

```python3
class Solution:
    def numberToWords(self, num: int) -> str:
        if num==0: return "Zero";
        dicts={1:"One",2:"Two",3:"Three",4:"Four",5:"Five",
               6:"Six",7:"Seven",8:"Eight",9:"Nine",10:"Ten",
               11:"Eleven",12:"Twelve",13:"Thirteen",14:"Fourteen",
               15:"Fifteen",16:"Sixteen",17:"Seventeen",18:"Eighteen",
               19:"Nineteen",20:"Twenty",30:"Thirty",40:"Forty",
               50:"Fifty",60:"Sixty",70:"Seventy",80:"Eighty",
               90:"Ninety",100:"Hundred",1000:"Thousand",
               1000000:"Million",1000000000:"Billion",
               1000000000000:"Trillion"}
        res=[];

        def recursion(num,flag):
            if num//1000:
                recursion(num//1000,flag+1);
            temp=num%1000
            if not temp: return;
            x=temp//100;
            y=(temp%100)//10;
            z=temp%10;

            '''判断数的构成'''
            if x:
                if y==0: 
                    if z==0: res.append("%s Hundred" %dicts[x])
                    else: res.append("%s Hundred %s" %(dicts[x],dicts[z]))
                elif y==1: res.append("%s Hundred %s" %(dicts[x],dicts[10+z]))
                else:
                    if z==0: res.append("%s Hundred %s" %(dicts[x],dicts[y*10]))
                    else: res.append("%s Hundred %s %s" %(dicts[x],dicts[y*10],dicts[z]))
            else:
                if y==0: res.append("%s" %dicts[z])
                elif y==1: res.append("%s" %dicts[10+z])
                else:
                    if z==0: res.append("%s" %dicts[y*10])
                    else: res.append("%s %s" %(dicts[y*10],dicts[z]))
            if flag:
                res.append("%s" %dicts[1000**flag]);

        recursion(num,0);
        output=" ".join(res);
        return output
```