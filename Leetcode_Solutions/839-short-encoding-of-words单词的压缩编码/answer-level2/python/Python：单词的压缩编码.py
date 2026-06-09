### 解题思路
1、discard函数会删去set中的元素，如果不存在，不会报错
2、只要确定set中没有重复单词即可

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        word=set(words)
        sum=0
        for i in words:
            for j in range(1, len(i)):
                word.discard(i[j:])
        for k in word:
            sum+=len(k)+1
        return sum
```