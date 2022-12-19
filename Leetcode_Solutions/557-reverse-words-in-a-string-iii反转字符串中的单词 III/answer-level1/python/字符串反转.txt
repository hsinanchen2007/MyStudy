### 解题思路
字符串反转问题：
       1. 首先将字符串切割为数组，将整个数组反转
       2. 将数组办为字符串再次进行反转
       3. "str1".join(str2),将两个字符串拼接
    #!/usr/bin/python
    # -*- coding: UTF-8 -*-
    str = "-";
    seq = ("a", "b", "c"); # 字符串序列
    print str.join( seq );
输出结果：a-b-c
### 代码

```python
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        str1 = s.split(" ")[::-1]
        return " ".join(str1)[::-1]
```