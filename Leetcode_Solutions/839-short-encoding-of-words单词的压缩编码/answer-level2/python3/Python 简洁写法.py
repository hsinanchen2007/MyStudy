### 解题思路
思路：逆序，排序，比较
1. 对words做逆序处理，之后排序 eg: ['me','time'] -> ['em','emit']
2. 排序后，若前一个词能在后一词的开头找到，则说明前一次可被后一词包含，即该词不会再占用空间
3. 被包含则 total += 0 否则 total += ( 前一词长度 + len(#) )

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = sorted(x[::-1] for x in words)
        total = 0
        for i in range(1,len(words)):
            if not words[i].startswith(words[i-1]):
                total = total + 1 + len( words[i-1])
        return  total + 1 + len(words[-1]) # 最后一个词必占用空间 
```