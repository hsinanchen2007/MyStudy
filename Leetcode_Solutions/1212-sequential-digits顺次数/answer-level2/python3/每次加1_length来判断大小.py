### 解题思路
看了别人的题解才发现自己太年轻了

### 代码

```python3
class Solution:
    def sequentialDigits(self, low, high):
        first  = int(str(low)[0])
        length = len(str(low))
        add = int("1"*length)
<!-- 每个位加一 -->
        res = []
        res_num = make_num(first, length)
        while res_num < low:
            first = first + 1
            res_num = make_num(first, length)
            if res_num == 123456789:
                break
            if first == 9:
                first = 0
                length = length + 1
                add = int("1" * length)
        while high >= res_num >= low:
            res.append(res_num)
            if res_num == 123456789:
                break
            if int(str(res_num)[0]) + length == 10:
                length = length + 1
                first = 1
                res_num = make_num(first, length)
                add = int("1" * length)
            else:
                res_num = res_num + add
        return res

<!-- 构造一个首数字为1的顺次数 -->
def make_num(first_num, length):
    result = first_num
    if length == 1:
        return first_num
    for i in range(length - 1):
        if first_num + i + 1 >= 10:
            return result
        else:
            result = result*10 + first_num + i + 1
    return result


```