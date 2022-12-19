### 解题思路
此处撰写解题思路
1.判断有多少成对字母，用k对记录
2.判断除了成对字母以外是否存在落单字母。如果存在落单字母，则返回2*k+1;否则返回2*k
**编码思路是**
采用一个标记数组，初始为全零。每找到一对字母，则将标记设置为1，表示为已经统计过。
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        k = 0
        length = len(s)
        flag = [0 for _ in range(length)]   #标记数组标记已经统计过的字母
        for i in range(0, length - 1, 1):
            for j in range(i+1, length, 1):
                if s[i] == s[j] and flag[i] == 0 and flag[j] == 0:
                    k += 1
                    flag[i] = 1
                    flag[j] = 1

        for i in range(0, length, 1):
            if flag[i] == 0:
                return 2*k+1

        return  2*k

```