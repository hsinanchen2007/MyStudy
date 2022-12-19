### 解题思路
因为英文字母有限，所以可以转换为两个26位的列表，比如a就是列表位置0，有一个a，对应位置的值加1。
如果chars中字母位置的值不小于word中字母位置的值，则说明可以拼写出来。

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        charsCnt = [0]*26
        for char in chars: # 统计给出的字母
            pos = ord(char)-ord('a')
            charsCnt[pos] += 1
        
        total_length = 0
        for word in words:
            tmpCnt = [0]*26
            can = True
            for char in word: # 统计单词中的字母
                pos = ord(char)-ord('a')
                tmpCnt[pos] += 1
            for i in range(26): # 比较
                if tmpCnt[i] > charsCnt[i]:
                    break
            else:
                total_length += len(word)
        return total_length
```