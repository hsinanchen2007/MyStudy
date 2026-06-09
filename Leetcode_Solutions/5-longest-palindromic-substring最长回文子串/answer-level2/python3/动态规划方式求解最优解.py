### 解题思路
此处撰写解题思路
初始化一个数组用来表示字符串中任何两个位置（包含端点字符）之间是否为回文。
从长度为1的子字符串开始进行检索，由于长度为1的字符串就是一个字符，则其必然为回文；
当末端字符的位置超出字符串的边界时，代表遍历结束，进行更长的子字符串的回文判断；
其中长度为1和长度为2的子字符串的判断要单独拎出来判断，为了进行动态规划奠定判断基础。
在检索最优解的过程中，可以进行最优解的记录和更新。
随着检索工作的完成，最优解也随之确定

### 代码

```python3
class Solution:
    def longestPalindrome(cls, s):
        s_length = len(s)
        if not s_length:
            return ''
        max_child_str = s[0]
        # 初始化字符串两个位置之间是否为回文的二维数组
        p = [[0 for _ in range(s_length)] for _ in range(s_length)]
        for length in range(1, s_length+1):
            for i in range(s_length):
                j = length + i - 1
                if j >= s_length:
                    break
                if length == 1 and s[i] == s[j]:
                    p[i][j] = 1
                    max_child_str = s[i:j+1]
                elif length == 2 and s[i] == s[j]:
                    p[i][j] = 1
                    max_child_str = s[i:j+1]
                # elif length == 3 and s[i] == s[j]:
                #     p[i][j] = 1
                #     max_child_str = s[i:j+1]
                elif p[i+1][j-1] and s[i] == s[j]:
                    p[i][j] = 1
                    max_child_str = s[i:j+1]
        return max_child_str
```