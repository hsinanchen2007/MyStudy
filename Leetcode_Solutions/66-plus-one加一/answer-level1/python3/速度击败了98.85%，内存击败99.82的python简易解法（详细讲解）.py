### 解题思路
首先我看到这题，刚刚开始想的过于简单了，将最后一位数加1就return，就结束了。
但是实际上它是每个列表项只能有单个数字。由于是单个数字，因此只会在末尾项为9时加1变成10会进位。
当然在此处我们无法知道他会一次进几位。
因此首先对末尾项，如果是九则将原来的列表int化，提取出数字然后对其+1
之后再将其列表化，当然，此处列表化肯定是从个位开始取，因此不满足题目要求的返回值
对其进行reverse反转。
注：刚刚开始我是直接return res.reverse(),发现返回值为None
原因是python中的reverse函数是直接将你原来的list进行反转，之后并不会返回反转后的值，而是返回list

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n=len(digits)
        a=0
        b=0
        res=[]
        if digits[n-1]==9:
            for i in range(n):
                a+=digits[i]*(10**(n-i-1))
            b=a+1
            while b>0:
                res.append(b%10)
                b//=10
            res.reverse()
            return res
        else:
            digits[n-1]+=1
            return digits
        


       
```