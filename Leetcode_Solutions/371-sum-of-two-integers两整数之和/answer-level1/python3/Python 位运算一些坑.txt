> 参考 [@jalan](/u/jalan/) 的[题解](https://leetcode-cn.com/problems/sum-of-two-integers/solution/wei-yun-suan-xiang-jie-yi-ji-zai-python-zhong-xu-y/). 

# 简介
这道题在参考的题解种思路很清楚, 如果同其他语言描述,可以写作:
```C++
public int getSum(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    while (b != 0) {
        int carry = a & b; //将存在进位的位置置1
        a = a ^ b; // 计算无进位的结果
        b = carry << 1;
    }
    
    return a;
}
``` 
总结一下, 对于python来说,主要的难点在于, python整数类型为`Unifying Long Integers`, 即无限长整数类型.
因此相较于其他语言的代码,Python代码需要一些额外的判定.

# 4bit 有符号整型加法
举个例子, 对于4bit有符号整型, 其数值范围为`[-8, 7]`
`-2 + 3` 可以通过补码计算 `1110 + 0011 =(1) 0001` 
```
    1 1 1 0
+   0 0 1 1
-----------
(1) 0 0 0 1 # 注意溢出
```
python 由于不知道符号位具体是第几位,因此需要进行的操作是
1. 将输入数字转化成无符号整数
2. 计算无符号整数相加并的到结果
3. 讲结果根据范围判定,映射为有符号整型

## 转化为4bit无符号整数
```python
a &= 0xF # a = a & 0b1111 = 1110 = 14
b &= 0xF # b = 0011 = 3
```

## 无符号整数加法
```python3
while b:
    carry = a & b
    a ^= b
    b = carry << 1 & 0xF # 模拟溢出操作
```
过程为
|         | 0    | 1    | 2    | 3    |
| ------- | ---- | ---- | ---- | ---- |
| `carry` |      | 0010 | 0100 | 1000 |
| `a`     | 1110 | 1101 | 1001 | 0001 |
| `b`     | 0011 | 0100 | 1000 | 0000 |

最后结果为 1 是没有问题的
但是对于 -2 + -2 , 最后结果为 1110 + 1110 = 1100 (12) 会出现问题

## 结果映射为有符号整数
首先有符号整数的值域应该为 `[-8, 7]` 对于初步运算的结果,当结果小于8直接返回就可.
对于大于 7 的结果, 可知符号位必为`1`. 现在的问题转化为, 如何通过位运算把负数转换出来.
假设python用的是 8bit 有符号整数,当前结果为`0000 1100`, 对应8bit有符号整数为`12`, 但结果应该为`-4`对应8bit有符号整数为`1111 1100`
通过两步转换可以得到:
1. 结果 与 `0b1111` 异或
2. 对异或结果按位取反
```python
~(a ^ 0xF)
```
这样就搞定了4bit 有符号加法,同理可以拓展到32bit
# 拓展到模拟 32bit 有符号整型加法
```python
class Solution:
    def getSum(self, a: int, b: int) -> int:
        a &= 0xFFFFFFFF
        b &= 0xFFFFFFFF
        while b:
            carry = a & b
            a ^= b
            b = ((carry) << 1) & 0xFFFFFFFF
            # print((a, b))
        return a if a < 0x80000000 else ~(a^0xFFFFFFFF)
```