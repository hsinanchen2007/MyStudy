### 解题思路
采用分而治之的思路，分为Billion/Million/Thousand/Left四个组，每个组可以由3位数表示。
正确的分组和表示相应的三位数。
ps:每个英文字母后加空格，最后使用rstrip()去掉最后的空格。繁杂但不难。

### 代码

```python3
#非负整数转换为相应的英文表示
#123->One Hundred Twenty Three
#12,345:Twelve Thousand Three Hundred Forty Five
#1,234,567->"One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
#1,234,567,891->"One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
class Solution:
    def numberToWords(self, num: int) -> str:
        #分组分治策略
        #special case:
        if not num:return "Zero"
        res=''
        #分组
        billion=num//1000000000
        million=(num-billion*1000000000)//1000000
        thousand=(num-billion*1000000000-million*1000000)//1000
        left=num-billion*1000000000-million*1000000-thousand*1000
        #个/十位的表示
        bit={1:"One ",2:"Two ",3:"Three ",4:"Four ",5:"Five ",6:"Six ",7:"Seven ",8:"Eight ",9:"Nine "}
        tenplace_20={10:"Ten ",11:"Eleven ",12:"Twelve ",13:"Thirteen ",14:"Fourteen ",15:"Fifteen ",16:"Sixteen ",17:"Seventeen ",18:"Eighteen ",19:"Nineteen "}
        tenplace={2:"Twenty ",3:"Thirty ",4:"Forty ",5:"Fifty ",6:"Sixty ",7:"Seventy ",8:"Eighty ",9:"Ninety "}
        #分组 1/2/3位数表示
        def twonum(num):#一位数和两位数的表示（在threenum中使用）
            if not num:return ""#为0时返回""
            elif num<10:return bit[num]#一位数时
            elif 9<num<20:return tenplace_20[num]#小于20的十位数表示
            else:
                tenp=num//10
                mo=num%10
                return tenplace[tenp]+bit[mo] if mo>0 else tenplace[tenp]
        def threenum(num):#三位数的表示
            if num<100:return twonum(num)
            if 99<num<1000:
                hud=num//100
                return bit[hud]+'Hundred '+twonum(num%100)
        Billionplace=threenum(billion)+"Billion " if billion>0 else ""
        Millionplace=threenum(million)+"Million " if million>0 else ""
        #print(thousand)
        Thousandplace=threenum(thousand)+"Thousand " if thousand>0 else ""
        res+= Billionplace+Millionplace+Thousandplace+threenum(left)
        return res.rstrip()

        
```