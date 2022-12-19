题解思路:

思路一：首先，将二进制字符串转换成十进制数；其次，将两个十进制数进行求和处理；最后，将和数转换成二进制字符串。
思路二：首先，将两个字符串转换到相同的长度，长度较短的字符串前面补“0”；其次，将字符串转换成list数组；再次，进行按位加；最后，将求和后的list数组转换成字符串类型。

思路一代码：
```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        
        return bin(int(a,2)+int(b,2))[2:]
```
其中，int(a,2) :将二进制字符串转换成十进制数
      bin(sum) :将十进制数转换成二进制字符串


思路二代码：
```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        
         len_a = len(a)
         len_b = len(b)
        
         if len_a > len_b:
             b = b.rjust(len_a,'0')
         elif len_a < len_b:
             a = a.rjust(len_b,'0')
             len_a = len_b
            
         a = list(a)
         b = list(b)
         temp = 0
         for index in range(len_a-1,-1,-1):
             count = 0
             if a[index] == '1':
                 count += 1
             if b[index] == '1':
                 count += 1
             if temp:
                 count += 1
            
             if count == 3:
                 a[index] = '1'
                 temp = 1
             elif count == 2:
                 a[index] = '0'
                 temp = 1
             elif count == 1:
                 a[index] = '1'
                 temp = 0
             else:
                 a[index] = '0'
                 temp = 0
                
         if temp:
             a.insert(0,'1')
        
         return ''.join(a)
```

