### 解题思路
按十进制对每位进行分类转换

### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        s = '%04d'%num
        w = 'MDCLXVI'
        i = 0
        result = ''
        while i < 4 :
            cur_n = int(s[i])
            cur_w = w[2*i]
            if cur_n == 9:
                t = w[2*i] + w[2*i - 2]
            elif cur_n > 4:
                t = w[2*i-1] + w[2*i]*(cur_n - 5)
            elif cur_n == 4:
                t = w[2*i] + w[2*i-1]
            else:
                t = w[2*i] * cur_n
            result += t
            i += 1
        return result
```