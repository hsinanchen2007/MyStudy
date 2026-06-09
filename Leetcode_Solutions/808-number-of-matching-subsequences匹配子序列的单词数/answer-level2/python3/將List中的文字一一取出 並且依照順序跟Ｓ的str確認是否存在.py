### 解题思路
將List中的文字一一取出 
並且依照順序跟Ｓ的str確認是否存在
若存在則找出存在的位置 必且取出後續的部分
若全部存在 則在結果+1

### 代码

```python3
class Solution:
    def numMatchingSubseq(self, S: str, words: List[str]) -> int:
        res = 0
        for word in words:
            S_c = S
            count = 0
            for w in word:
                if w in S_c:
                    index = S_c.find(w)
                    count += 1
                    if index + 1 < len(S_c):
                        S_c = S_c[index+1:]
                else:
                    break  
            if count == len(word):
                res += 1
        return res        



                    
                    
```