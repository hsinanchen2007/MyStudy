### 解题思路
1. 解题目标：
    - 字符串去重
    - 顺序不变，只是相邻的相同字符有数字替代
2. 解题思路：
    - 遍历字符串
    - 临时变量t存储上一个字母
    - 当前字符i
    - 比较t和i
    - 相同，末尾数字加1
    - 不同，加i和1进去
    - t=i

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        temp = ''
        res = []
        for i in range(len(S)):
            if S[i] == temp:
                res[len(res)-1] = str(int(res[len(res)-1]) + 1)
            else:
                res.append(S[i])
                res.append(str(1))
            temp = S[i]
        if len(S) <= len(res):
            return S
        else:
            return ''.join(res)

```