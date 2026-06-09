### 解题思路
我的思路：将a、b先反转, a、b长度短的末位补0；然后分情况进行讨论即可：

![image.png](https://pic.leetcode-cn.com/8494fd85ac33ba04c7c6d9c9c4573bca27c3ef8667c4e6dc65f99c88083223c6-image.png)

最后需要判断一下进位若为1，则结果多一位1，最后反转结果输出。
时间复杂度：o(N)
空间复杂度：o(N)

### 代码

```python3
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        jinwei = 0
        a = "".join(reversed(a))
        b = "".join(reversed(b))
        len_a = len(a)
        len_b = len(b)
        result = ''
        if len_a>len_b:
            for i in range(len_b,len_a):
                b += '0'
        else:
            for i in range(len_a,len_b):
                a += '0'
        len_a = len(a)
        for i in range(len_a):
            if a[i] == '0' and b[i] == '0' and jinwei == 0:
                result += '0'
            elif (((a[i] == '0' and b[i] == '1') or (a[i] == '1' and b[i] == '0')) and jinwei == 0) or (a[i] == '0' and b[i] == '0' and jinwei == 1):
                result += '1'
                jinwei = 0
            elif (((a[i] == '0' and b[i] == '1') or (a[i] == '1' and b[i] == '0')) and jinwei == 1) or (a[i] == '1' and b[i] == '1' and jinwei == 0):
                result += '0'
                jinwei = 1
            else:
                result += '1'
                jinwei = 1
        if jinwei == 1:
            result += '1'
        result = "".join(reversed(result))
        return result

```