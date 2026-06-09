暴力匹配+字典，写得一手烂代码 crying....
```python
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not s or not words: return None
        word_num = len(words)
        word_size = len(words[0])
        res = []
        
        # 创建一个字典
        map = dict()
        for word in words:
            if word in map:
                map[word] += 1
            else:
                map[word] = 1
        
        # 开始遍历 s
        i = 0
        while i < len(s)-word_num*word_size+1:
            count = 0
            tmp_map = map.copy()
            j = i
            tmp = s[j:j+word_size] 
            # print("I:", i)
            # print("TMP:", tmp)
            while (j < len(s)-word_size+1) and (tmp in tmp_map) and (tmp_map[tmp] > 0):
                tmp_map[tmp] -= 1
                j += word_size
                count += 1
                tmp = s[j:j+word_size]
                # print(" tmp_map:",tmp_map)
            
            if count == word_num:
                res.append(i)
            i += 1
            
        return res
                
```
