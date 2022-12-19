### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1=="0" or num2=="0":
            return "0"
        m=len(num2)
        carry=0
        ans=[]
        #字符串2 分别每一位 乘以 字符串1 结果保存到ans
        # 得到每一位乘积  然后 相加
        for i in range(m):
            t=10**(m-1-i)
            x=ord(num2[i])-ord('0')
            j = len(num1) - 1
            tmp=[]
            while j>=0 or carry!=0:
                if j>=0:
                    carry+=x*(ord(num1[j])-ord("0"))
                    j-=1
                tmp.append(str(carry%10))
                carry//=10
            ans.append("".join(tmp[::-1])+str(t)[1:])

        def addStrings( num1: str, num2: str) -> str:
            i = len(num1) - 1
            j = len(num2) - 1
            carry = 0
            ans = []
            # 保证两个数组都遍历到，因为可能一个数组比较短
            # 为什么carry!=0 因为当i=0和j=0时 可能有进位一个 所以需要最后一步carry%10
            while i >= 0 or j >= 0 or carry != 0:
                # 一个数组一个相加 因为可能存在一长一短的情况
                if i >= 0:
                    carry += ord(num1[i]) - ord("0")
                    i -= 1
                if j >= 0:
                    carry += ord(num2[j]) - ord('0')
                    j -= 1
                ans.append(str(carry % 10))
                carry //= 10
            # 需要翻转
            res = ''.join(ans[::-1])
            return res
        res="0"
        for s1 in ans:
            res=addStrings(res,s1)
        return res
```