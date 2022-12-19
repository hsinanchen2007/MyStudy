1. 第一种解法：转换成十进制相加再利用队列转换成二进制。（注意对输入是0 0的判断）
```
def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if int(a)==0 and int(b)==0: return '0'
        sum_ab = sum([int(x) << (len(a) - 1 - i) for i, x in enumerate(a)]) + sum([int(x) << (len(b) - 1 - i) for i, x in enumerate(b)])
        tmp = []
        while sum_ab>0:
            tmp.insert(0, str(sum_ab%2))
            sum_ab //= 2
        return ''.join(tmp)
```

2. 第二种解法：在1的基础上，修改求和函数
```
def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if int(a)==0 and int(b)==0: return '0'
        sum_a, sum_b = 0, 0
        for i in range(len(a)):
            sum_a = sum_a*2 + int(a[i])
        for i in range(len(b)):
            sum_b = sum_b*2 + int(b[i])
        sum_ab = sum_a + sum_b
        tmp = []
        while sum_ab>0:
            tmp.insert(0, str(sum_ab%2))
            sum_ab //= 2
        return ''.join(tmp)
```

3. 第三种解法：在1的基础上，利用递归修改求和函数
```
 def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if int(a)==0 and int(b)==0: return '0'
        def convert(a,sum_a,i):
            sum_a = sum_a*2 + int(a[i])
            if i != len(a)-1:
                return convert(a, sum_a,i+1)
            return sum_a
        sum_a = convert(a, 0, 0)
        sum_b = convert(b, 0, 0)
        sum_ab = sum_a + sum_b
        tmp = []
        while sum_ab>0:
            tmp.insert(0, str(sum_ab%2))
            sum_ab //= 2
        return ''.join(tmp)
```

4. 第四种解法：a b左侧用0补齐，逐位相加
```
def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if int(a)==0 and int(b)==0: return '0'
        n = max(len(a),len(b))
        a, b = a.zfill(n), b.zfill(n)
        tmp = []
        indicator = 0
        for i in range(1,len(a)+1):
            tmp.insert(0, str((int(a[-i]) + int(b[-i]) + indicator)%2))
            indicator = (int(a[-i]) + int(b[-i])+ indicator)//2
        if indicator: tmp.insert(0, str(indicator))
        return ''.join(tmp)
```

5. 第五种解法：位运算（耗时低内存小），首先转化成数字x,y，进行XOR运算得到无进位的相加结果x，再进行&并左移一位得到y，对x y循环采用上述操作直到y=0
```
x, y = int(a, 2), int(b, 2)#表示以二进制读取进来的
while y:
    answer = x^y
    carry = (x&y)<<1
    x, y = answer, carry
return bin(x)[2:]
```
