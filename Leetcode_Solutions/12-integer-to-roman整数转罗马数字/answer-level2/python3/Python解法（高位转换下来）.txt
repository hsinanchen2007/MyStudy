![image.png](https://pic.leetcode-cn.com/8712efb2f9c6c66d02f5f5edd273f09ef32c2597317e80fbdd0b37d220b4f023-image.png)

怎么感觉这题比罗马数字转整数简单？

```
class Solution:
    def intToRoman(self, num: int) -> str:
        d = {1000:'M',
             900:'CM',
             500:'D',
             400:'CD',
             100:'C',
             90:'XC',
             50:'L',
             40:'XL',
             10:'X',
             9:'IX',
             5:'V',
             4:'IV',
             1:'I'}
        string = ''
        for n, s in d.items():       
            string += s * (num//n)
            num = (num % n)
            
        return string
        
c = Solution()
for i in range(1,4000):
    print(i,':',c.intToRoman(i))
```
