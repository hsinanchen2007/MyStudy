### 解题思路
此处撰写解题思路

要知道needle在haystack第一次出现的位置， python可以用字符串切割方法。
1. 如果needle为空， 返回0；
2. 用needle去切割haystack.则会得到一个列表。如果列表长度为1，说明needle不存在，返回-1;
3. 若列表长度大于1，则出现位置是列表[0]的字符串长度。


### 代码

```python
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle == "":
            return 0
        re_list = haystack.split(needle)
        if len(re_list) == 1:
            return -1
        return len(re_list[0])
        
```