### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def replaceSpace(self, s):
        """
        :type s: str
        :rtype: str
        """
        str_list = []
        #把字符串放入数组
        for i in s:
            str_list.append(i)
            print(str_list)

        #遍历列表
        for i, item in enumerate(str_list):
            if item == " ":
                str_list[i] = "%20"
        #把列表转换为字符串
        res = "".join(str_list)
        return res
```