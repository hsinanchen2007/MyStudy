思路：
从尾部开始遍历
- 当不是空格时，利用标志位来记录找到字母
- 判断是尾部的空格则继续向前遍历
- 判断不是尾部的空格说明最后一个单词记录完毕，跳出。

```
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0
        flag = 0
        for i in range(len(s)-1,-1,-1):
            if s[i] != ' ':              #当从尾部找到字母，则标志位置1
                count += 1
                flag = 1
            if s[i] == ' ' and flag == 0: #如果是尾部的空格则继续向前遍历
                continue
            if s[i] == ' ' and flag == 1: #不是尾部的空格说明最后一个单词记录完毕，跳出。
                break
        return count
```

