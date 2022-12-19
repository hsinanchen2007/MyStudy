### 解题思路
该思路较复杂：
1、写一个反转函数，反转list
2、将输入整数转换成list，调用反转函数得到反转后的list
3、将反转后的list转换为str，比较是否溢出，溢出返回0，否则返回实际int型反转值
4、注意处理特殊情况，个位数反转可优先特殊处理（我第一次提交没处理导致执行出错）

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        def list_reverse(y: list) -> list:
            z = []
            if y[0] == '-':
                y = y[1:]
                for i in range(len(y)):
                    z.append(y.pop())
                if z[0] == '0':
                    z = z[1:]
                z.insert(0, '-')
            else:
                for i in range(len(y)):
                    z.append(y.pop())
                if z[0] == '0':
                    z = z[1:]
            return z

        input_list = list(str(x))
        if len(str(x)) == 1:
            return x
        output_list = list_reverse(input_list)
        out_s = ""
        for i in output_list:
            out_s = out_s + i
        if output_list[0] == '-':
            if int(out_s) < int(math.pow(2, 31))*(-1):
                return 0
            else:
                return int(out_s)
        else:
            if int(out_s) > int(math.pow(2, 31)) - 1:
                return 0
            else:
                return int(out_s)
```