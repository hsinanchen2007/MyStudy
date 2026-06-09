小白写题解，也不知道这算是什么派系。
```
class Solution:
    def plusOne(self, digits):
        s = 0
        length = len(digits)
        for i in range(length):
            s += pow(10, i) * digits[length-1-i]
        result = s + 1
        final_result = []
        for j in range(length-1, -1, -1):
            final_result.append(result % 10)
            result = result // 10
        if set(final_result) == {0}:
            final_result.append(1)
        return final_result[::-1]
```
首先就是得到加一之后的值，然后再把他们变成数组【这个部分还可以再优化】。需要处理的特殊情况为，[9],[9,9,9]这类需要多一位的数组。
我在最后用set来判断，如果得到的数组全为0，可以理直气壮地在前面添个1。

