
![image.png](https://pic.leetcode-cn.com/660075789d3b577f6eaa1d644039d3354cf006fd49bfcd3e3c7ba03f5e0f4f54-image.png)

### 算法
从后往前，分别计算0到该位数中1的个数，有1再加上1后面的数，有0就跳过。
如2123中1的个数即0-3、0-20、0-100、0-2000中1的个数的和，再加上23,
如11034中1的个数即0-4、0-30、0-1000、0-10000中1的个数再加上34和4034。

### 代码

```python3
class Solution:
    def countDigitOne(self, n: int) -> int:
        if n == 0: return n  #明明说n大于等于1
        if n <= 9: return 1
        one = [1]   
        #one[i]存储[0, 10**i)中含有1的个数  
        #one[i] = 10*one[i-1]+10**i  在下方迭代的时候更新
        num = []    #从后往前存储各个位的数字
        while n != 0:
            num.append(n%10)
            n //= 10

        # 初值r
        r = 0 if num[0] == 0 else 1
        now = num[0]    #记录到该位位置，数的大小，有1时加之
        for i in range(1, len(num)):
            # print(num[i], r, now, one)
            one.append(10*one[-1]+10**i)
            if num[i] == 0:
                continue
            elif num[i] == 1:
                r += now + one[-2] + 1
            else:
                r += 10**i + num[i]*one[-2]  
                #如果num[3]=5，即0-5000中1的个数，
                #即10**3(1000-1999一千个数中千位数上的1)加上0-999中1的个数*5，num[i]*one[-2]
            now += num[i]*10**i
        return r


```