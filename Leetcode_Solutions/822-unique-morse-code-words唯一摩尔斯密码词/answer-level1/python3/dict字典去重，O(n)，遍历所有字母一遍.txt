### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        moerseDict ={"a":".-","b":"-...","c":"-.-.","d":"-..","e":".","f":"..-.","g":"--.","h":"....","i":"..","j":".---","k":"-.-","l":".-..","m":"--","n":"-.","o":"---","p":".--.","q":"--.-","r":".-.","s":"...","t":"-","u":"..-","v":"...-","w":".--","x":"-..-","y":"-.--","z":"--.."}     
        #特殊情况
        size = len(words)
        if(size <= 1): return size

        #通常情况
        res={}
        for item in words:
            mid = list(item.lower())
            midres = ""
            for letter in mid:
                midres += moerseDict[letter]
            res[midres] = 1  #用于去重
        return len(res.keys())






```