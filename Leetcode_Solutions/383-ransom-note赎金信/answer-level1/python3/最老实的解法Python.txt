本题的实质就是：保证A中的字符B中都有，且数目都是B的大于等于A
1.首先遍历字符串，如果A中的字符有一个没在B中，自然返回FALSE
2.利用字典统计字母的个数，对应字母相互减.如果有一个B字母中数目少于A，返回false，否则最终返回TRUE
具体解法如下：
```
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for ranstr in ransomNote:
            if ranstr not in magazine:
                return False
        dic_ransom={}
        for ranstr in ransomNote:
            dic_ransom[ranstr]=dic_ransom.get(ranstr,0)+1
        dic_m={}
        for mag in magazine:
            dic_m[mag]=dic_m.get(mag,0)+1
        for k,v in dic_ransom.items():
            for key ,values in dic_ransom.items():
                if dic_ransom[k]-dic_m[k]>0:
                    return False
        else:
            return True
            
```
```
```

  