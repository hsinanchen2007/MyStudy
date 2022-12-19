### 解题思路
法一：与自身减一相与，有多少个1，则计算多少次。
法二：与1相与，计算值为一的次数。 缺点在于，负数进行右移操作时，会从负数变为正数。
法三：多定义一个flag，进行左移。避免法二的问题。但其计算次数仍为1所在的最高位数。

### 代码

```
#法一:
class Solution:
    def hammingWeight(self, n: int) -> int:
        num = 0
        while n != 0:
            num += 1
            n = n &(n-1)
        return num
```


```
#法二:
class Solution:
    def hammingWeight(self, n: int) -> int:
        num = 0
        while n != 0:
            if n & 1 == 1:
                num += 1
            n = n >> 1
        return num
```
```
#法三:
class Solution:
    def hammingWeight(self, n: int) -> int:
        num = 0
        flag = 1
        while flag:
            if (n & flag) :
                num += 1
            flag = flag << 1
        return num
```