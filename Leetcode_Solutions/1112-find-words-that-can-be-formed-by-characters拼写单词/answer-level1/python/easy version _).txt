### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        count = 0
        flag = 0
        for string in words:
            for i in string:
                if string.count(i) > chars.count(i):
                    flag = 0
                    break 
                else:
                    flag = 1
                    continue 
            if flag == 1:
                count = count + len(string)
        return count 


```