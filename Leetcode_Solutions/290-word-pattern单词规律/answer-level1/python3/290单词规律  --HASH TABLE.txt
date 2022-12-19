### 解题思路
1.pattern:"abba"可以映射为"1221"
2.strs:将strs 用split分开成数组,["red" "Blue" "Blue" "Red"]=>"1221"
3.编写wordPattern:借助HASH TABLE临时存储{letter,num}，如果存在于H.T.中的字母，则返回其num值，否则（不存在H.T中的字母）添加到HASH表中再返回num值。

### 代码

```python3
class Solution:
    def wordPattern(self, pattern: str, strs: str) -> bool:
        def patternform(item):
            n=1
            HT={}#HASH表临时存储{letter:n}
            flag=''
            for letter in item:
                if letter in HT:#若存在于HASH表中，则取出值
                    flag+=str(HT[letter])
                else:#不存在于HASH表中，则加入并取出值
                    HT[letter]=n
                    flag+=str(n)
                    n+=1
            return flag
        refer=patternform(pattern)
        strlist=strs.split()
        tocheck=patternform(strlist)
        return True if refer==tocheck else False
        

                    
                    
            
                
                    



```