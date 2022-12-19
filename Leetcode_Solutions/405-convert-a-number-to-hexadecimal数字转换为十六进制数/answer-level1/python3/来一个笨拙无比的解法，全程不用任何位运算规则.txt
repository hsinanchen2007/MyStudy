### 解题思路
全程手动转换，累死我了


### 代码

```python3
class Solution:
    def toHex(self, num: int) -> str:
        l1 = [i for i in range(16)]
        l2 = [str(i) for i in range(10)] + ['a', 'b', 'c', 'd', 'e', 'f']
        d = dict(zip(l1, l2))
        lb = ['0000', "0001", '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001', '1010', '1011', '1100', '1101', '1110', '1111']
        db = dict(zip(lb, l2))
        ss = ''

        if num == -(2**31):
            return "80000000"

        l = []
        if num<0:
            num = -num
            while num//2>0:
                l.insert(0, d[num%2])
                num = num//2
            l.insert(0, d[num%2])

            for i in range(len(l)):
                if l[i] == '0':
                    l[i] = "1"
                else:
                    l[i] = "0"
            l = ['1'] + ["1"]*(31-len(l)) + l

            carry = 1
            for j in range(31, -1, -1):
                if carry + int(l[j]) == 2:
                    l[j] = '0'
                    carry = 1
                else:
                    l[j] = '1'
                    break
            
            ss = ss.join(l)
            l = []
            for i in range(8):
                l.insert(i, db[ss[i*4:(1+i)*4]])

        elif num<10:
            return str(num)
        else:
            while num//16>0:
                l.insert(0, d[num%16])
                num = num//16
            l.insert(0, d[num%16])
        
        ss = ''.join(l)
        return ss
```