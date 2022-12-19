### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        res = 0
        # 构建hash数组
        hash = [0 for i in range(26)]
        for i in chars:
            hash[ord(i) - 97] += 1
        for word in words:
            word_hash = [0 for i in range(26)]        
            for w in word:
                word_hash[ord(w) - 97] += 1
                if word_hash[ord(w) - 97] > hash[ord(w) - 97]:
                    break
            # 注意这里的用法, 不熟悉这个语法的话也可以用一个 flag 来标记
            else:
                res += len(word)
        return res
```