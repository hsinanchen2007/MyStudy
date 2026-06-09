### 解题思路
1.count[256] 为ASCII表全集， 256字节，每个index标识该index的字符出现次数。
2.如果无相同字符， 在遍历的同时记录字符的出现次数以及索引
3.如果有相同字符， current_pre指针后移至相同字符的下一个字符处
也可以把index和count合并成一个表示字符有无出现，这样可以省一半的内存

### 代码

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length=len(s)
        pre = 0
        current_pre = 0
        last = 0
        maxlength = 0
        current_length = 0
        index = [-1 for _ in range(256)]
        count = [0 for _ in range(256)]
        for i, char in enumerate(s):
            count[ord(char)] += 1
            if count[ord(char)] == 1:
                index[ord(char)] = i
                current_length += 1
            else:
                if current_pre<=index[ord(char)] + 1:
                    current_pre = index[ord(char)] + 1
                count[ord(char)] -= 1
                current_length = i - current_pre + 1
                index[ord(char)]=i
            if current_length > maxlength:
                pre = current_pre
                last = i
                maxlength = current_length
                if maxlength>=length-current_pre:
				    return maxlength
        return maxlength
```