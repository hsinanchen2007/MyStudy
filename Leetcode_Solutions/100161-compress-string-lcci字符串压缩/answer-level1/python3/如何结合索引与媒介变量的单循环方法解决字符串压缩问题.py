### 解题思路
此处撰写解题思路

    params
    --------
        S: 输入的字符串

    return
    --------
        s: 存储压缩字符串
        media: 存储连续字符的数量，每个字符的第一次出现即为1
    
    
    步骤：
        
        1. 在输入字符串后加上任意不等于原字符串S最后一个字符的字符，我这里添加的为空格 =>[目的]=>
    最后一次比较不等写入s，防止S最后的若干个字符相等无法退出。
        2. 循环：
            比较相邻两个字符[i-1 vs i]是否相等：
                相等 => media+1 
                不相等 => 此时前者结束计数，写入s，初始化media，开始重新计数
            当[i]为添加的'\s'时，结束循环。
        3. 三元运算符输出判断

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        s = ''
        media = 1
        S += ' '
        for i in range(1, len(S)):
            if S[i-1]==S[i]:
                media += 1
            else:
                s += S[i-1] + str(media)
                media = 1
        return s if len(s)<len(S[:-1]) else S[:-1]
```