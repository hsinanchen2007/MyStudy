### 解题思路
- 3个数字一组
- 从左向右, 但是需要将下标转换成从右向左对应的位数, 方便判断当前位于哪一位
- 可以先用数组存每个字符串, 最后统一用空格join
- 注意10~19的特殊处理, 需要将下一位数字也用掉, 但是如果下一位在千位的话还是需要输出千位
- 注意百的处理, 要和数字在一起, 如果数字被忽略了百也要被忽略, 而千位不能这样
- 注意0的特殊处理, 如果位于千位, **且上一个不是高一级的千位**的话, 也要输出对应的千位

### 代码

```python
class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return 'Zero'
        single = [
            'Zero', 'One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven',
            'Eight', 'Nine'
        ]
        tens = {
            10: 'Ten',
            11: 'Eleven',
            12: 'Twelve',
            13: 'Thirteen',
            14: 'Fourteen',
            15: 'Fifteen',
            16: 'Sixteen',
            17: 'Seventeen',
            18: 'Eighteen',
            19: 'Nineteen',
            20: 'Twenty',
            30: 'Thirty',
            40: 'Forty',
            50: 'Fifty',
            60: 'Sixty',
            70: 'Seventy',
            80: 'Eighty',
            90: 'Ninety'
        }
        kilos = {3: 'Thousand', 6: 'Million', 9: 'Billion'}
        s = str(num)
        n = len(s)
        res = []
        ignored = False
        for i in range(n):
            # 先转成从右向左的位数
            index = n - i - 1
            if s[i] != '0' and not ignored:
                if index % 3 == 1:
                    # 十位
                    if s[i] == '1':
                        # 忽略下一位的数字
                        res.append(tens[int(s[i:i + 2])])
                        ignored = True
                    else:
                        res.append(tens[int(s[i]) * 10])
                elif not ignored:
                    res.append(single[int(s[i])])
                if index % 3 == 2:
                    res.append('Hundred')
            else:
                ignored = False
            if index in kilos and res[-1] not in kilos.values():
                res.append(kilos[index])
        return ' '.join(res)
```