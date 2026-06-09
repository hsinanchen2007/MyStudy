### 解题思路

单独的一个罗马字母代表一个数值，一个罗马数字就是这些字母的组合，也就是这些字母所代表数值的简单叠加，一般来说，只需要将这些字母所代表的数值加起来就是该罗马数字所代表的整数数值，如
‘XI’就是X（10）+I（1）等于11。
只是需要注意的是：在一个罗马数字中，如果一个罗马字母a所代表的数值小于其后一个字母c所代表的数值，则需要减去a所代表的数值。
如‘IV’，I代表的数值为1，V代表的数值为5，1<5，所以应该先减去1，然后加上5。


### 代码

```python
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        str2int={'I':1,
                'V':5,
                'X':10,
                'L':50,
                'C':100,
                'D':500,
                'M':1000
        }
        lens=len(s)-1
        result=0
        for i,c in enumerate(s):
            if i!=lens:
                if str2int[c]<str2int[s[i+1]]:
                    result-=str2int[c]
                else:
                    result+=str2int[c]
            else:
                result+=str2int[c]
        return result

            
```