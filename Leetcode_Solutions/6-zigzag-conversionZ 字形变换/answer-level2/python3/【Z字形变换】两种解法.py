## 方法一：按行排序
### 思路：
 通过字符串遍历，并保存到对应行的字符串中，最后按顺序衔接在一起
``` python3
class Solution:
    def convert(self, s: str, num_rows: int) -> str:
        if num_rows < 2 or len(s) < num_rows:
            return s
        new_s = ["" for _ in range(num_rows)]
        i, flag = 0, -1
        for c in s:
            new_s[i] += c
            if i == 0 or i == num_rows - 1:
                flag = -flag
            i += flag
        return "".join(new_s)
```
## 方法二：按行访问
### 思路：
通过每行中的index方法获取对应字符
```
class Solution:
    def convert(self, s: str, num_rows: int) -> str:
        if num_rows < 2 or len(s) < num_rows:
            return s
        new_s = ''
        for i in range(num_rows):
            k = 0
            index = i
            # 第一行：对应index为：index = 2 * k * (num_rows - 1)
            if i == 0:
                while index < len(s):
                    new_s += s[index]
                    k += 1
                    index = 2 * k * (num_rows - 1)
            # 最后一行：index = (2 * k + 1) * (num_rows - 1)
            elif i == num_rows - 1:
                while index < len(s):
                    new_s += s[index]
                    k += 1
                    index = (2 * k + 1) * (num_rows - 1)
            # 中间几行存在两种情况：
            # 1、index = 2 * k * (num_rows - 1) + i
            # 2、index = 2 * (k + 1) * (num_rows - 1) - i
            else:
                while index < len(s):
                    new_s += s[index]
                    index = 2 * (k + 1) * (num_rows - 1) - i
                    if index < len(s):
                        new_s += s[index]
                    k += 1
                    index = 2 * k * (num_rows - 1) + i
        return new_s
```
