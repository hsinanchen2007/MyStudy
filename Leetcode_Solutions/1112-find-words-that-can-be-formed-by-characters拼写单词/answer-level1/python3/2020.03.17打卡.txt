### 解题思路
每个词汇依次判断，能否由字母表拼写成功。

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans = 0
        for i in words:
            chars_t = list(chars).copy()
            for j in i:
                judge = 1
                if j not in chars_t:
                    judge = -1
                    break
                else:
                    chars_t.remove(j)   #已经使用的字母从字母表中剔除，防止重复使用。
            ans = ans+len(i) if judge == 1 else ans
        return ans

                


```