### 解题思路
根据前一次的构造后一次的字符串，记录长度和开始字母
### 代码

```python3
class Solution:
    def countAndSay(self, n):
        # 这个n最大也才30，其实直接枚举还快多了
        # 在这的话感觉用递归就可以了
        init_str = "1"
        if n == 1:
            return init_str
        result_dict = {}
        result_dict[1] = init_str
        def make_str(str_in):
            length = 0
            begin = str_in[0]
            res = ""
            for i in range(len(str_in)):
                if str_in[i] == begin:
                    length += 1
                else:
                    res += str(length)
                    res += begin
                    begin = str_in[i]
                    length = 1
            res += str(length)
            res += begin
            return res
        for i in range(1, n):
            result_dict[i + 1] = make_str(result_dict[i])
        return result_dict[n]
```