想说的其实已经标注在代码里了，水平不够，写的比较长
```
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        #对于小数s = 0.ab(c),c长度为m,则 s * (10 ** m) = ab[c的前m-2位].**(c)
        # s * (10 ** m) - s = 
        # s = (ab[c的前m-2位][c的后两位 - ab]) / (10 ** m * 100 - 100)
        # 从而， 记前缀ab 长度为n，则 s = (ab[c的前m-2位][c的后两位 - ab]) / (10 ** (m + n) - 100 * n)
        # 分母为 "9" * m + "0" * n，分子未知。但分子/分母 = numerator/denominator
        # 我们考虑 denominator 如何转化成 "9" * (m-1) + "0" * n 的形式，求出m,n即可

        flag = ""
        if  numerator / denominator < 0 or (numerator > 0 and denominator == 2147483648):
            flag = '-'
        numerator = abs(numerator)
        denominator = abs(denominator)
        
        count = 1
        while(denominator % 10 == 0):
            count *= 10
            denominator //= 10              #计算分母的后缀0个数
        a = len(str(numerator))
        b = len(str(denominator))
        if b > a:
            numerator *= (10**(b-a))
            count *= (10**(b-a))

        pre = numerator//denominator
        numerator = (numerator % denominator)
        if numerator == 0:
            if pre == 0 or (pre >= count and pre % count == 0):
                return flag + str(int(pre/count))
            return flag + str(pre/count)        #整除

        post = numerator/denominator #小数部分
        if len(str(post)) < 16:
            return flag + str((pre + post)/(count))      #判断是否循环      
        
        tem = str(denominator)
        if all(i == "9" for i in tem):   #先求出m
            m = len(tem)   #此时numerator == (ab[c] - ab]),n == 0,ab = 0,即 s = pre.(numerator[扩充长度至m]) / count
            numerator = str(numerator)
            post = "(" + '0'*(m - len(numerator)) + numerator + ")"
            if pre == 0 or (pre >= count and pre % count == 0) :
                pre //= (count)
                pre = str(pre) + '.'+ str(count)[1:] + post
            else:
                pre /= (count)
                pre = str(pre) + post
            return flag +  pre
        

        
        l = 12
        post = str(int(numerator * (10**l)/denominator))  #不要四舍五入，取12位小数
        m = 1
        s_post = "0"*(l-len(post)) + post
        num = numerator
        while(1):
            tem = (int('9'*m)* numerator)%denominator   #分子/分母 = numerator/denominator
            if l < m:
                num = num * (10**12) % denominator
                post =  str(int(num * (10**12)/denominator))
                if all(i=='0' for i in post):     #并不是循环小数
                    j = -1
                    while(s_post[j] == '0'):
                        j -= 1
                    j += 1
                    s_post = s_post[0:j]
                    if pre == 0 or (pre >= count and pre % count == 0) :
                        pre //= (count)
                        pre = str(pre) + '.'+ str(count)[1:] + s_post
                    else:
                        pre /= (count)
                        pre = str(pre) + s_post
                    return flag + pre
                s_post += ("0"*(12-len(post)) + post)
                l += 12
            tem /= denominator
            if len(str(tem)) < 16:  
                break
            m += 1
        n = 0
        if tem != 0:
            n = len(str(tem).split(".")[1])
        while(l < m + n):
            num = num * (10**12) % denominator
            post =  str(int(num * (10**12)/denominator))
            s_post += ("0"*(12-len(post)) + post)
            l += 12
        s_post = s_post[0:n] + "(" + s_post[n:n + m] + ")"
        if pre == 0 or (pre >= count and pre % count == 0) :
            pre //= (count)
            pre = str(pre) + '.'+ str(count)[1:] + s_post
        else:
            pre /= (count)
            pre = str(pre) + s_post
        return flag + pre
```
