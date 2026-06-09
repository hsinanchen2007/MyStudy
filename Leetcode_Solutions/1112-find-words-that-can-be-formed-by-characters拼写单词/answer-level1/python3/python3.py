### 解题思路
单词的每个字母提出来在字母表中找对应，找到了就将字母表中对应的删除一个（消耗掉）。直到每个字母都能在字母表中“消耗”一个对应字母，结果+=该单词长度。

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        chars_list = list(chars)
        res = 0
        for word in words:
            chars_list_temp = chars_list[:]
            exit_flag = False
            for element in word:
                if chars_list_temp.count(element) == 0:
                    exit_flag = True
                    break
                chars_list_temp.remove(element)
            if exit_flag == True:
                continue
            res += len(word)
        
        return res
```