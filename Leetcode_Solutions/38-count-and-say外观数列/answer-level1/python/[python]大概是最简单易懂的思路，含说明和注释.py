```python
class Solution:
    def countAndSay(self, n: int) -> str:
        """
        从前往后统计数字个数，直到结尾或遇见不同数字
        有几个就在行首添加数字几
        """
        temp = ''
        string = '1'
        count = 1
        for j in range(1, n):
            temp = ''
            for i in range(len(string)):
                if i + 1 < len(string):  # 如果有下一位
                    if string[i] == string[i + 1]:  # 如果下一位的字符等于这一位字符，计数+1
                        count += 1
                    else:  # 不等就合并到temp
                        temp += str(count) + string[i]
                        count = 1
                else:  # 没有下一位就将直接合并
                    temp += str(count) + string[i]
                    count = 1
            string = temp


        return string
```
