**原理：**
将num1和num2切割为n个长度为k的部分
`a = a[0]*10^(0*k)+a[1]*10^(1*k)+...+a[n1]*10^(n*k)`
`b = b[0]*10^(0*k)+b[1]*10^(1*k)+...+b[n2]*10^(n*k)`
则`a*b = (a[0]*b[0])*10^(0*k) + (a[0]*b[1]+a[1]*b[0])*10^(1*k) + ... +(a[0]*b[i+j]+a[1]*b[i+j-1]+...+a[i]*b[j]+...+a[i+j]*b[0])*10^((i+j)*k) + ... +(a[n1]*b[n2])*10^((n1+n2)*k)`
需要计算每一项的底数部分，再按顺序连接起来
考虑到32位整数最大为`2147483647`，k的取值不应超过3（k取4时，当两数均为110位，第i+j项最多有`28*9999*9999=2,799,440,028‬`超出，取3时则为`37*999*999=36926037`）
**复杂度分析：**
切片时间复杂度O(n1+n2),计算底数部分乘法时间复杂度O(n1*n2),拼合部分加法时间复杂度O(n1+n2),其中n1和n2分别为num1和num2的长度。整体上，k越大，乘法计算次数越少，代码效率越高
**拓展：**
当num的长度增长时，k的取值范围会被压缩，当最大长度不超过6453位时k可取3，当最大长度不超过438,216‬时k可取2，最终退化为k=1
```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        num1_list,num2_list,res,n1,n2,temp = [],[],[],num1,num2,0
        k = 2 #把两数截成k个字符长度的数组
        while len(n1)>k: #处理num1
            num1_list.append(n1[-k:])
            n1 = n1[:-k]
        if len(n1)>0:
            num1_list.append(n1)
        while len(n2)>k: #处理num2
            num2_list.append(n2[-k:])
            n2 = n2[:-k]
        if len(n2)>0:
            num2_list.append(n2)
        res_list = [0 for i in range(len(num1_list+num2_list))]
        for i in range(len(num1_list)):
            for j in range(len(num2_list)): #计算两两乘积
                res_list[i+j] += int(num1_list[i]) * int(num2_list[j])
        for m in range(len(res_list)):
            temp_str = str(res_list[m]+temp)
            if len(temp_str)>k:
                res.append(temp_str[-k:])
                temp = int(temp_str[:-k])
            else:
                res.append('0'*(k-len(temp_str))+temp_str)
                #print(res)
                temp = 0
        res = ''.join(res[::-1]).lstrip('0')
        if res != '':
            return res
        else: 
            return '0'
```
