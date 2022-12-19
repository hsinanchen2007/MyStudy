解题思路：题目特点是‘[]’里的字符是需要展开的，并且可以嵌套，因此可以用递归
1、对每个字符判断一次
       - 如果是数字，要考虑多位数
       - 如果是‘[’，遍可以递归
       - 如果是']'，则递归返回
       - 如果是字母，则作为本次递归的结果，暂存

时间复杂度：
由于字符串`S`的每个字符都遍历1次，因此，为O(N)
![1.png](https://pic.leetcode-cn.com/a613d055ba0e9953684cd33fb536861cf920da83288dfed303b45f348837e5fb-1.png)

```
class Solution:
    def decodeString(self, s: str) -> str:
        def dfs(i):
            # 初始化
            res, k = '', 0

            # 遍历字符串s
            while i < len(s):
                if '0' <= s[i] <= '9':  # 数字
                    k = k*10 + int(s[i])
                elif s[i] == '[':  # 递归信号
                    i, tmp = dfs(i+1)
                    res += k * tmp  # 保存结果
                    k = 0  # 同一层可能还有其他的数字，因此要清空
                elif s[i] == ']':  # 递归完成信号
                    return i, res
                else:  # 字符
                    res += s[i]
                i += 1

            return res
        
        return dfs(0)
```