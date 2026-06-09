## 简单几行代码轻松实现：


- 列表求和
- 加1
- 结果转化成列表

话不多说，直接上代码：
**方法一：**

```
class Solution(object):
    def plusOne(self, digits):
        sums = 0
        for i in range(len(digits)):
            sums += 10**(len(digits)-1-i)*digits[i]
        sums_str = str(sums + 1)
        return [int(j) for j in sums_str]
```
**方法二**
借鉴在力扣上一种比较好的方法重写一下,略有差异
```
class Solution(object):
    def plusOne(self, digits):
        sums = 0
        for i in digits:
            sums = sums * 10 + i #10进制乘以10，进行累积和；
        sums_str = str(sums + 1)
        return map(int, list(sums_str))
```
**方法三**
适合Python及其它语言的写法：

```python []
class Solution(object):
    def plusOne(self, digits):
        # 从最低位开始做加法运算
        for i in range(len(digits)-1, -1, -1):
            if digits[i] != 9:
                digits[i] += 1
                return digits
            digits[i] = 0
        ans = [0] * (len(digits) + 1)
        ans[0] = 1
        return ans;
```
```Java []
class Solution {
    public int[] plusOne(int[] digits) {
        for (int i = digits.length-1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        int[] ans = new int[digits.length+1];
        ans[0] = 1;
        return ans;
    }
}
```
觉得还行的话，留下您的赞（手动比心）