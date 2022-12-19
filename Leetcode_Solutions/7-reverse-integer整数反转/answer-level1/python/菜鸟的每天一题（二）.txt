### 解题思路
- 首先判断输入数字得正负，若为负数，变为正数处理，并将对应标志位 置1
- 然后通过while判断当前x除以10得结果 循环更新x直到x<10 得到一个装有各个数位数字得列表
- 使用python得列表元素反转顺序函数，直接反转
- 遍历每一个元素，乘以对应得数位，得到反转之后得数
- 判断是否超出32位数字得取值范围，若超出，返回0
- 判断前面负数得标志位是否为1，若为1，将最后结果加上负号
- 输出

### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        num = []
        result = 0
        minus_flag = False

        if x > 0:
            x = x
        elif x < 0:
            x = -x
            minus_flag = True
        
        while x // 10 is not 0:
            num.append(x % 10)
            x = x // 10
        else:
            num.append(x)
        
        length = len(num)
        if length > 1:
            num.reverse()
            for i in range(length):
                result += num[i] * 10 ** i
            if result > 2147483647 or result < -2147483647:
                return 0
            else:
                if minus_flag:
                    return -result
                else:
                    return result
        else:
            if minus_flag:
                return -num[0]
            else:
                return num[0]

        

```