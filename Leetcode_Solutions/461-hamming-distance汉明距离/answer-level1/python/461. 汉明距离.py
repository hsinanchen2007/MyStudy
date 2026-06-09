1. 自己开始想的
- bin(x) 两个数二进制处理
- 补位处理
- 循环对比
```
class Solution(object):
    def onList(self, num):
        # list or number or string
        return list(bin(num)[2:])

    def addLen(self, L, add_len):
        add_L = []
        for i in range(0, add_len):
            add_L.append('0')
        L = add_L + L
        return L

    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        l_x, l_y = self.onList(x), self.onList(y)
        xy_abs = abs(len(l_x) - len(l_y))

        if len(l_x) > len(l_y):
            l_y = self.addLen(l_y, xy_abs)
        else:
            l_x = self.addLen(l_x, xy_abs)

        print l_x, l_y

        i = 0
        data = 0
        while(i < len(l_x)):
            if l_x[i] != l_y[i]:
              data = data + 1
            i = i + 1
        return data
```

2. 异或处理.count(1)
- x ^ y 异或处理: ^ 按位异或运算符：当两对应的二进位相异时，结果为1
- count(1) 有多少个1
```
# return bin(x ^ y).count('1')
```

3. 效率会更高些
```
class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        data = 0
        for i in bin(x ^ y):
            if i == '1':
                data += 1
        return data
```
