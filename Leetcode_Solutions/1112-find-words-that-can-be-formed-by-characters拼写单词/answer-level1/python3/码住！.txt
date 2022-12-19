### 解题思路
不会太多方法 这里就是直接暴力搜索
如果单词中有字母在字母表中 就在字母表中把这个字母去掉
PS ab.replace是有返回值的不是在原字符串上修改

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        sum = 0
        for word in words:
            n = len(word)
            ab = chars
            word_sum = 0
            for i in range(n):
                a = ab.find(word[i])
                if a != -1:
                    ab = ab.replace(word[i],' ',1)
                    word_sum = word_sum + 1
                else:
                    break
                if word_sum == n:
                    sum = sum + n          
        return sum
```