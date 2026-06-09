### 解题思路
完全借鉴[dexin](https://leetcode-cn.com/problems/pattern-matching-lcci/solution/mo-shi-pi-pei-zui-ji-chu-jie-fa-by-dexin/)的思路，只不过换成了python的解法。

### 代码

```python3
class Solution:
    def patternMatching(self, pattern: str, value: str) -> bool:
        from collections import defaultdict
        dict1 = defaultdict(int) 
        index = 0
        dict2 = dict()
        outpattern = []
        for sub in pattern:
            if not sub in dict2:
                dict1[index]+=1
                outpattern.append(index)
                dict2[sub] = index
                index +=1 
            else:
                dict1[dict2[sub]]+=1
                outpattern.append(dict2[sub])
        print(dict1)

        if dict1[0]==0:
            return len(value)==0

        if dict1[1]==0:       ## 仅有一个模式
            if len(value) ==0:
                return True
            if len(value)%(dict1[0])!=0:
                return False
            else:
                length = int(len(value)/dict1[0])
                substr = value[:length]
                for index in range(length,len(value),length):
                    if value[index:index+length] != substr:
                        return False
            return True
        
        if dict1[1]==1 or dict1[0]==1:  ##其中一个的个数为1
            return len(value)!=0

        for index,substr in enumerate(value):
            a0_len = index
            a0_string = value[:index]
            if (len(value)-a0_len*dict1[0]) % dict1[1]:
                continue
            
            b1_len = int((len(value)-a0_len*dict1[0])/dict1[1])
            if b1_len<0:
                continue
            
            temppos = 0
            b1_string = ""
            match = True
            for sub in outpattern:
                #print("yes")
                if sub==0:
                    print(value[temppos:temppos+a0_len])
                    if value[temppos:temppos+a0_len] != a0_string:
                        match = False
                        break
                    temppos += a0_len
                elif sub==1:
                    if not b1_string:
                        b1_string = value[temppos:temppos+b1_len]
                    elif value[temppos:temppos+b1_len]!=b1_string:
                        match = False
                        break
                    temppos += b1_len
            if match and a0_string!=b1_string:
                return True
        return False
        
```