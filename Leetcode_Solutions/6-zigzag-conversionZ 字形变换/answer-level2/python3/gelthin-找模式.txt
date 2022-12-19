### 解题思路
这里只要找到一个模式，然后一直循环即可。
对于 numRows = 3,
0   | 4   |
1 3 | 5 7 |
2   | 6   |
只需注意到  0 1 2 3 对应的位置即可  [0], [1,3], [2]  每个数分别加 4 得到下一组数
其余numRows = 4, 只需照着推就好


注意：
1. 没有考虑特例 numRows=1 致使错误. 写代码，特别是 硬编码的部分，一定要注意是否会有特例出错

### 代码

```python3
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2:
            return s

        all_list = [[0],]
        len_s = len(s)
        num = 2*numRows-2
        for i in range(1, numRows-1):
            current_list = []
            current_list.append(i)
            current_list.append(num-i)
            all_list.append(current_list)
        all_list.append([numRows-1])

        result = ""
        for x in all_list:
            if len(x) == 1:
                t = x[0]
                while t < len_s:
                    result += s[t]
                    t += num
            if len(x) == 2:
                t1, t2 = x[0], x[1]
                while t2<len_s:
                    result += s[t1]
                    result += s[t2]
                    t1 += num
                    t2 += num
                if t1 < len_s:
                    result += s[t1]
        return result
```