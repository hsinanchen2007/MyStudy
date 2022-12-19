### 解题思路

- 通过256 散列表确定每个字符的次数
- 遍历散列表比较每一个字符出现次数

### 代码

```python
class Solution(object):
    def CheckPermutation(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        # 先判断大小是否相同, 不同则直接返回false。
        if len(s1) != len(s2):
            return False

        s1_str = [0]*256
        s2_str = [0]*256
        # 通过256 散列表确定每个字符的次数
        for i in range(len(s1)):
            s1_str[ord(s1[i])] = s1_str[ord(s1[i])]+1
            s2_str[ord(s2[i])] = s2_str[ord(s2[i])]+1

        # 遍历散列表比较每一个字符出现次数
        for i in range(len(s1_str)):
            if s1_str[i] != s2_str[i]:
                return False
        return True


if __name__ == '__main__':
    s1 = 'abc'
    s2 = 'bac'
    solution = Solution()
    print(solution.CheckPermutation(s1, s2))
```