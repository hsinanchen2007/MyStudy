### 解题思路
1. 建立一个包含键盘三行字母大小写的列表Keys；
2. 设置标志flag，设置初始值True，表示符合条件；
3. 遍历列表中的单词
- 获取第一个字母的行数；
- 接着遍历后面的字母，检查是否与第一个字母相等；
- 如果不相等则将flag的值改为False，跳出循环。
- 如果后面的字母都符合要求，则将该单词添加到新的列表中。

### 代码

```python3
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        Keys = ['QWERTYUIOPqwertyuiop', 'ASDFGHJKLasdfghjkl', 'ZXCVBNMzxcvbnm']
        Target = []
        for word in words:
            flag = True
            if word[0] in Keys[0]:
                index = 0
            elif word[0] in Keys[1]:
                index = 1
            else:
                index = 2
            for i in range(1, len(word)):
                if word[i] not in Keys[index]:
                    flag = False
                    break
            if flag:
                Target.append(word)
        return Target
```