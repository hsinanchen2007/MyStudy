### 解题思路
![image.png](https://pic.leetcode-cn.com/3ed91e184ccb75730ff689898e52167cc89c3e1814608d3a85b1caf69bbc451c-image.png)

就用普通的字符串的思路解决就可以了。

### 代码

```python
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """

        list_num = [""] * numRows
        len_s = len(s)

        if numRows == 1:
            return s

        count_num = 0
        i = 0
        while i < len_s:
            
            for j in range(numRows):
                # print j
                if i < len_s:
                    list_num[j] += s[i]
                    i += 1
            for j in range(numRows-2):
                # print j
                if i < len_s:
                    list_num[numRows-2-j] += s[i]
                    i += 1

        print list_num[0], list_num[1]
        return "".join(list_num)

            
```