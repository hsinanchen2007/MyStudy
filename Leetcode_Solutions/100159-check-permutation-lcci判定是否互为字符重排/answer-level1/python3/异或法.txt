我们知道异或是满足交换律的，如果两个字符串相同，那么所有元素异或后最终结果应为0，基于这个思想我们可以写出相应的代码
```
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        # 如果长度不等可以直接返回False
        if len(s1) != len(s2):
            return False

        ans = 0

        # 分别取两个字符串的字符 
        for char_1, char_2 in zip(s1, s2):
            print(char_1, char_2)
            ans ^= ord(char_1) ^ ord(char_2) # 用ord进行转换

        if ans == 0:
            return True
        else:
            return False
```
整个思路还是比较简单的，遇到这种判断相同元素的，除了直接暴力，还可以往异或方向去思考一下