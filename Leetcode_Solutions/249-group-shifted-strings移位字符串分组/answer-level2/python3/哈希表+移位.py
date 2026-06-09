### 解题思路
思路很简单，对于每个单词，例如abc,转换成 012, 即 word-word[0] 对于每个字母。
然后把012放入字典，后面查找就行。
但是连接的时候，要加个连字符，比如'a',否则， am=012会有一样的结果。

### 代码

```python3
class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        dic = {}
        for w in strings:
            temp = w
            s = ""            
            dis = ord(temp[0])
            for c in temp:
                d = (ord(c)-dis)%26 #shift
                s += 'a' + str(d) #加连字符
            if s not in dic.keys():
                dic[s] = [w]
            else:    
                dic[s].append(w)
            
        return [dic[suibian] for suibian in dic.keys()]
```