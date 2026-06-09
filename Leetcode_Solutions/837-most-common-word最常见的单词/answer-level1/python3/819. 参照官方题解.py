### 解题思路
写几点注意事项吧：
1. 标点符号首先要处理掉
2. 分割的时候原先写split的时候，我写的split(' ')这样由于标点的替换操作就会引起多余的' ' 在列表中。直接使用split()就好。
3. collection.Counter()的使用不熟练。
4. 最后取最大的方法，其实跟其他取最大值或者最小值的方法很相似，可还是不熟练。以求得最大值赋给best，然后继续遍历，如果有更大的值再赋给best，如果没有保持原来的best不变即可。

### 代码

```python3
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph = paragraph.lower()
        
        for c in "!?',;.":
            paragraph= paragraph.replace(c, ' ')
        
        para = paragraph.split()
        para_dict = collections.Counter(para)
        
        ans, best = '', 0
        for word in para_dict:
            if para_dict[word] > best and word not in banned:
                ans = word
                best = para_dict[word]
        
        return ans
```