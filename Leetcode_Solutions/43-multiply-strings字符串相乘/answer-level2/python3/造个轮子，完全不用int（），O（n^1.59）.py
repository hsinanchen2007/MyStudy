```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        #返回对应的 ASCII 数值，或者 Unicode 数值
        num1 = [ord(i)-ord('0') for i in list(num1[::-1])]  
        num2 = [ord(i)-ord('0') for i in list(num2[::-1])]
        z = self.karatsuba(num1, num2)        
        while len(z) > 1 and z[-1] == 0:
            del z[-1]
        return ''.join(map(str, reversed(z)))

    def add(self, num1, num2):
        z, carry = [], 0
        #补齐长度
        n = len(num1) - len(num2)
        if n > 0:
            num2 += [0]*n
        else:
            num1 += [0]*-n
    
        for i in range(len(num1)):
            tmp = num1[i] + num2[i] + carry
            z += [tmp % 10]
            carry = tmp // 10
        if carry:
            z += [carry]
    
        return z


    def sub(self, num1, num2):
        z, carry = [], 0
        #补齐长度
        n = len(num1) - len(num2)
        if n > 0:
            num2 += [0]*n
        
        for i in range(len(num1)):
            tmp = num1[i] - num2[i] + carry
            z += [tmp % 10]
            carry = tmp // 10
            
        return z

    def karatsuba(self, num1, num2):    
        #补齐长度
        n = len(num1) - len(num2)
        if n > 0:
            num2 += [0]*n
        else:
            num1 += [0]*-n
    
        #基链
        if len(num1) == 1:
            return self.add([num1[0]*num2[0]],[0])
    
        #分割
        n_2 = (len(num1) + 1) >> 1
        A, B = num1[n_2:], num1[:n_2]
        C, D = num2[n_2:], num2[:n_2]
    
        # karatsuba乘法计算
        tmp0 = self.karatsuba(A, C)
        tmp1 = self.karatsuba(B, D)
        tmp2 = self.karatsuba(self.add(A, B), self.add(C, D))
        tmp2 = self.sub(self.sub(tmp2, tmp0), tmp1)
    
        z = self.add(tmp1, [0] * (n_2 << 1) + tmp0)   #移位相加
        z = self.add(z, [0] * n_2 + tmp2)
    
        return z
```
