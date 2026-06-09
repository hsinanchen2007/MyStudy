#### 思路
思路挺简单，举个栗子：`word = 'apple'`，`abbr = 'a2e'`，我们把`abbr`中的数字换成相同数量的星号，存在`tmp`中，则`tmp = 'a**e'`，比较`tmp[i]`与`word[i]`是否相同，星号直接跳过即可。
#### 代码
```
class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        # 维护tmp（过程有些繁琐，能力有限）
        tmp = ''
        i = 0
        while i < len(abbr):
            if abbr[i] == '0':  # 处理测试案例里有0的情况
                tmp += abbr[i]
                i += 1
            elif abbr[i].isalpha():  # 是字母直接加到tmp中
                tmp += abbr[i]
                i += 1
            else:
                # 如果abbr = a13b，这里的数字表示13，而不是1和3，所以如果是数字还要考虑下一位是不是数字
                if i < len(abbr)-1 and not abbr[i].isalpha() and not abbr[i+1].isalpha(): 
                    tmp += '*' * int(abbr[i] + abbr[i+1])
                    i += 2
                else:
                    tmp += '*' * int(abbr[i])
                    i += 1
        # 将tmp与word比较
        if len(tmp) != len(word): # 长度不等直接返回False
            return False
        else:
            for j in range(len(tmp)):
                if tmp[j] != '*' and tmp[j] != word[j]:  # 只比较非*部分
                    return False
        
        return True
```
#### 复杂度分析
- 时间复杂度：O(N)，遍历两次
- 空间复杂度：O(N)，使用了`tmp`
