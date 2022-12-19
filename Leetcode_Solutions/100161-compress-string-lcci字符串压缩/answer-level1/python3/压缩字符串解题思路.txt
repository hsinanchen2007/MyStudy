### 解题思路
通过遍历字符串记录直到下一个不同字符串的时当前字符出现的次数 
依次执行后获得压缩后字符串
通过压缩前后的字符串长度比较决定输出源字符串还是压缩字符串

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        i = 0
        len_s = len(S)
        res = ''
        while i < len_s:
            j = i
            # 遍历字符串，遇到与上个字符不同时统计上个字符的出现次数
            while j < len_s and S[j] == S[i]:
                j += 1
            res += S[i] + str(j - i)
            # 将遍历的起点变更为下一个字符的位置
            i = j
        # 根据转换后的字符长度判断输出的字符串
        if len(res) < len_s:
            return res
        else:
            return S
```