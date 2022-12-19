### 解题思路
找到两个变换对应的操作：
分别是：
    除以2 对应 >>1 (右移一位)
    减1 对应 &1

第一次写的代码是位运算

```python3
        result = 0
        while num != 0:
            if num & 1:
                result += 1
                # num = num >> 1 << 1
                num = num ^ 1
            else:
                num = num >> 1
                result += 1
        return result
```
提交之后速度比较慢，感觉是每次都要 `result += 1` 耽误了运行时间，所以观察了一下输入的二进制格式。
发现二进制的长度对应了需要`>>`的次数，里面的1对应了需要`^1`的次数，因为python的bin()开头是1，而这个1，位运算到最后一步肯定是`^1`而不是`>>`(因为已经变成0了)，所以真正需要右移的次数是length-1，而需要`^1`的次数是count(bin())
最后总的操作次数为 `length - 1 + count('1')`
若简化为一行代码为 `return len(str(bin(num))[2:]) - 1 + str(bin(num))[2:].count('1')`
不知道这样会不会导致`str(bin(num))[2:]`计算量两次，对python的具体实现还是初学，不是太了解，保险起见选择了个使用一个中间变量临时保存。

[2:]是python的bin函数会有0b开头，不知道有没有更优雅的方式处理。

### 代码

```python3
class Solution:
    def numberOfSteps(self, num: int) -> int:
        tmp = str(bin(num))[2:]
        return len(tmp) - 1 + tmp.count('1')
```