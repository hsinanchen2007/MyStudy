### 解题思路
先把paragraph里该去的标点符号去掉；再把被ban掉的单词去掉；将剩下的字符串切分，出现次数最多的单词就是题目要求的返回值，代码如下。

### 代码

```python3
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        L = paragraph.replace(',',' ').replace('.','').replace('!','').replace('?','').replace(';','').replace("'",'').lower()
        for word in banned:
            L = L.replace(word, '')
        words = L.split()
        new_set = set(words)
        dictionary = {}
        for item in new_set:
            dictionary.update({item: words.count(item)})
        return max(zip(dictionary.values(), dictionary.keys()))[1]
        
        



        
                
            


```