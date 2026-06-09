### 解题思路
逐个比较就行，注意处理一下长度
### 代码

```python3
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        def compare(word1,word2):
            for char1,char2 in zip(word1,word2):
                if  order.index(char1)<order.index(char2):
                    return True
                elif order.index(char1)==order.index(char2):
                    continue
                elif order.index(char1)>order.index(char2):
                    return False
            if len(word1)>len(word2):
                return False
            return True
        for i in range(len(words)-1):    
            if not compare(words[i],words[i+1]):
                    return False
        return True


        


```