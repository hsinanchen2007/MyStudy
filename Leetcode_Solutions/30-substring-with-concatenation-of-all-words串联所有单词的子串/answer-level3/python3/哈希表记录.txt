不行，太慢了，但练习练习哈希表（字典）吧

### 代码

```python3
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if s == "" or words == []: return []
        n = len(s)
        l_word = len(words[0])
        length = len(words)*l_word
        flag = True
        out = []
        # 哈希表1
        hash1 = {}
        hash2 = {}
        for word in words:
            hash1.setdefault(word, 0)
            hash1[word] += 1
        for i in range(0,n-length+1):
            # 构建哈希表2
            for j in range(i,i+length,l_word):
                hash2.setdefault(s[j:j+l_word], 0)
                hash2[s[j:j+l_word]] += 1
            # 判断
            if hash1 == hash2:
                 out.append(i)
            hash2 = {}

        return out 
                    




```