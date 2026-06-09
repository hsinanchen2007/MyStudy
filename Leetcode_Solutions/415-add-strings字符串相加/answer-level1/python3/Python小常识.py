琢磨了一下怎么切换最快：
```python
i = ord('1') - 48  # 比int('1')快
s = str(i)  # 比chr(i+48)快
a = [ord(i) - 48 for i in s]# 用列表比直接用string快
```
没有用int方法超过96，基本上就是我最快的意思吧？
![score.png](https://pic.leetcode-cn.com/00bcc317a3f4b0fc6bd56945612e883471767fdd777472bfd6660d7ade489933-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-08-07%20%E4%B8%8B%E5%8D%886.49.09.png)

```python
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        answer, left = ([(ord(i)-48) for i in num2], [(ord(i)-48) for i in num1]) if len(num1) < len(num2) else ([(ord(i)-48) for i in num1], [(ord(i)-48) for i in num2])
        carry = 0
        for i in range(-1, -len(left)-1, -1):
            answer[i] += (left[i] + carry)
            if answer[i] >= 10:
                answer[i] -= 10
                carry = 1
            else:
                carry = 0
        if not carry:
            return ''.join([str(i) for i in answer])
        for i in range(len(answer)-len(left)-1, -1, -1):
            answer[i] += 1
            if answer[i]>=10:
                answer[i] -= 10
            else:
                return ''.join([str(i) for i in answer])
        return '1'+''.join([str(i) for i in answer])
```