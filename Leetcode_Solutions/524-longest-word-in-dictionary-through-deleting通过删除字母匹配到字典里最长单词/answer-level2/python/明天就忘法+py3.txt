### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        # 先对d数组字符串长度 进行从大到下排序 当最长的长度相等时 比较第一个字符
        d.sort(key=lambda x:(-len(x),x))
      
        for word in d:
            index=0
            for i in range(len(s)):
                if word[index]==s[i]:
                    index+=1
                if index==len(word):
                    return word
        return ""
```