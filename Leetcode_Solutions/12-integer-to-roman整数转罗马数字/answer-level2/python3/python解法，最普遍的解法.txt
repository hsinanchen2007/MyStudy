应该是最常见的解法，直接暴力减掉。百分之八十。
![image.png](https://pic.leetcode-cn.com/806907768fa4ac3d95392d626c090b86d81a048b08e2b0ab4b974b9ba043d21e-image.png)
啊我好菜啊，前两题真难，弄个简单的缓缓脑子。

`class Solution:
    def intToRoman(self, num: int) -> str:
        outstr=''#输出字符串
        dic={1:'I',5:'V',10:'X',50:'L',100:"C",500:'D',1000:'M',4:'IV',9:'IX',40:'XL',90:'XC',400:'CD',900:'CM'}#字典
        #从高到低遍历字典key
        for i in sorted(list(dic.keys()),reverse=True):
            #逐个相减按照规律写入字符串
            while num>=i:
                num-=i
                outstr+=dic[i]
        return outstr`