### 解题思路
首先，对于一个整数，我们需要判定它的符号。如果它是负数的话，就先忽略掉符号，最后加上就好，这样方便计算。紧接着，要判断该数是否能在32位的储存空间里放下。其次，要判断整数里的0. 在做反转时，我们需要去除掉x从右到左所有的零，直到一个非零的位数。这样能保证再反转过来时第一位是非零数，这样返回的整数才有意义。然后通过对称数位调换位置，逐渐向中间趋近的方式来调换数字的位置。最后再加上相应的符号以及跟内存容量比较即可得出正确的答案。

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        Minus = False #用于判断正负数的变量
        Zero = True #用于判断给定数字是否为0的变量
        if x > 2**31-1 or x < -2**31: # 如果超过储存空间则直接返回0.
            return 0 
        z = list(str(x)) #以列表的形式对数字进行排列比较方便
        if z[0] == "-": #判断是否为负数，如果是则去除第一个符号(z[0]), Minus 改为True
            z = z[1:] 
            Minus = True
        for i in range(len(z)): #判断数字是否为0，如果是则直接返回0
            if z[i] != "0":
                Zero = False
        if Zero == True:
            return 0
        while z[-1] == "0": #从左至右一项一项检查是否为0
            del z[-1]
        if len(z)%2 != 0: #判断数位是否对称（是否为偶数）
            for i in range(int((len(z)-1)/2)):
                z[i],z[-(i+1)] = z[-(i+1)],z[i]
        else:
            for i in range(int(len(z)/2)):
                z[i],z[-(i+1)] = z[-(i+1)],z[i]   
        if Minus == True:#数字为负数
            x ="-"
            for i in range(len(z)):
                x = x+z[i]#将列表转换为数字
            x =int(x)
            if x > 2**31 - 1 or x < -2**31:
                return 0
            else: 
                return x
        else:#数字为正数
            x =""
            for i in range(len(z)):#数字为正数
                x = x+z[i] #将列表转换为数字
            x = int(x)
            print(x)
            if x > 2**31 - 1 or x < -2**31:
                return 0
            else:
                return x
```