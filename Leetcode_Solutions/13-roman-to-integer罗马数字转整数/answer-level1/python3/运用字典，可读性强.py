### 解题思路

用到两个字典：正常数据字典（dic），特殊两位字符串的字典（dic_two）。

1、先建立一个可变字符串y，初始值与输入值相同。用于修改字符串的值，而原字符串s仅用于最初的遍历。


2、首先遍历整个字符串，判断是否存在后面位数比前面位数大的情况，即循环变量为i的for循环。

       获取前一个字符与当前字符组成的两字节字符串check是否在dic_two中，若存在，将y中对应位置替换为空格。

3、将修改后的字符串y按空格进行切片成列表list_split，用于后续遍历。

4、遍历list_split，每一项再遍历每个字符，利用dic字典查询对应简直，加到result中。

5、返回结果。

### 代码

```python3
class Solution:
    def romanToInt(self, s):
        dic={'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        dic_two = {'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900}
        result = 0
        y = s
        for i in range(len(s)):
            if i == 0:
                continue
            else:
                check = s[i-1]+s[i]
                if dic_two.get(check) is not None:
                    y = y.replace(check, ' ')
                    result += dic_two[check]
        list_split = y.split(' ')
        for j in list_split:
            for m in j:
               result += dic[m]
        return result


```