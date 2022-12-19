作为一名微电子专业的学生，我用Python编写的二进制加法基本是仿照**硬件加法器**的思路来写的，所以整体的运行速度还是很不错的。

但是牺牲了比较多的存储资源，所以空间复杂度还是比较夸张的。
基本代码如下：
```Python
def addBinary(self, a: str, b: str) -> str:
    length_a = len(a)
    length_b = len(b)
    cin = '0'
    string_res = ''
    if length_a >= length_b:
        for i in range(-1, -1*length_a-1, -1):
            aa = a[i]
            bb = b[i] if i >= -1*length_b else '0'
            if aa == bb:
                if aa == '0':
                    string_res = cin + string_res
                    cin = '0'
                else:
                    string_res = cin + string_res
                    cin = '1'
            else:
                if cin == '0':
                    string_res = '1' + string_res
                    cin = '0'
                else:
                    string_res = '0' + string_res
                    cin = '1'
    else:
        for i in range(-1, -1*length_b-1, -1):
            aa = a[i] if i >= -1*length_a else '0'
            bb = b[i] 
            if aa == bb:
                if aa == '0':
                    string_res = cin + string_res
                    cin = '0'
                else:
                    string_res = cin + string_res
                    cin = '1'
            else:
                if cin == '0':
                    string_res = '1' + string_res
                    cin = '0'
                else:
                    string_res = '0' + string_res
                    cin = '1'
    if cin == '1': string_res = '1' + string_res
    return string_res
```
**提交结果如下：**
![image.png](https://pic.leetcode-cn.com/aa08f2f3010002a5d891f56988f45e97e424dba4615715f3315f0cc239fc837f-image.png)
