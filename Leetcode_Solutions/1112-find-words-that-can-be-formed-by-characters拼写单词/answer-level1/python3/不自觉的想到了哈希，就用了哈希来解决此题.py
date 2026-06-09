### 解题思路
利用哈希建立 字母为键与字母出现次数为值的哈希 遍历单词列表 每次哈希 最后满足能全在哈希找到映射的单词输出结果

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        res = ""
        for word in words:
            hash = {}
            for i in range(len(chars)):
                hash[chars[i]] = hash.get(chars[i],0)+1
            count = 0
            for w in word:
                if hash.get(w,0) >= 1:
                    hash[w] = hash.get(w,0)-1
                    count += 1
                else:
                    break
            if count == len(word):
                res += word
        return len(res)
```