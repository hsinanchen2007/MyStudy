### 解题思路
1. 如果字符串为空，返回S，否则转2
2. 遍历字符串S，比较前一位与后一位是否相等，若相同则为同一字符串，cnt+1,否则转3
3. 记录当前字符与出现次数，并置cnt = 1，开始统计下一字符出现次数，遍历结束，转4
4. 判断S与res长度，返回较短的字符串，若相等则返回S 

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        if S == '':
            return S
        res = ''
        length = len(S)
        cnt = 1
        for i in range(length):
            if i+1 <= length - 1 and S[i] == S [i+1]:
                cnt +=1
            else:
                res += S[i] + str(cnt)
                cnt = 1
        return res if len(res) < len(S) else S

```