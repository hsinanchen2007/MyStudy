

```
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = str(s)
        v = 0
        l = 0
        while l<len(s):
            if s[l]=='I':
                v+=1
            elif s[l]=='V':
                if l!=0:
                    if s[l-1]=='I':
                        v+=3
                    else:
                        v+=5
                    
                else:
                    v+=5
                    
                    
            elif s[l]=='X':
                if l!=0:
                    if s[l-1]=='I':
                        v+=8
                    else:
                        v+=10
                else:
                    v+=10
                        
            elif s[l]=='L':
                
                if l!=0:
                    if s[l-1]=='X':
                        v+=30
                    else:
                        v+=50
                else:
                    v+=50
                    
                    
            elif s[l]=='C':
                if l!=0:
                    if s[l-1]=='X':
                        v+=80
                    else:
                        v+=100
                else:
                    v+=100
    
            elif s[l]=='D':
                if l!=0:
                    if s[l-1]=='C':
                        
                        v+=300
                    else:
                        v+=500
                else:
                    v+=500
                
            elif s[l]=='M':
                if l!=0:
                    if s[l-1]=='C':
                        v+=800
                    else:
                        v+=1000
                else:
                    v+=1000
                
            l+=1
        
        return v
```
##### 我采用的是for 循环遍历罗马数字，然后判断第一个罗马数字不进行寻找前一个罗马数字，因为如果不给予判断它会自动去寻找到最后一个的罗马数字，会导致错乱，判断完是否第一个字符串后，然后判断前一个罗马数字是否是有'I','X','C',如果有就按照题目给出的规则来赋值，至于为什么题目规则给我的IV是4，而我只给3呢？是因为题目规则给出的是总数，而我结合上一个罗马数字总数也是等于4，所以我为什么给的数字要比规则里面的要低。因为加上前一个罗马数字的值就可以等于规则的总数了。