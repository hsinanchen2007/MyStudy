 ```
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        '''
        class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        '''
        我的思路：
        1、先将字符串都倒序，因为从个位数开始加起
        2、用0在末尾填充，保证两个字符串长度一致
        3、增加一个变量add，表示进位多少；res用来拼接结果
        4、%取余数得到当前位的数字，//得到进位数字。
        5、不能忘记最后还有一个进位要加上，如果进位是0，则不用加上
        6、将结果字符串res翻转过来
        '''
        num1_rev = num1[::-1]
        num2_rev = num2[::-1]
        n1 = len(num1_rev)
        n2 = len(num2_rev)
        n = max(n1,n2)
        num1_rev += '0'*(n-n1)
        num2_rev += '0'*(n-n2)
        add = 0
        res = ''
        for i in range(n):
            su = int(num1_rev[i])+int(num2_rev[i])+add
            res += str(su%10)
            add = su//10
        if add !=0:
            res += str(add)
        res = res[::-1]
        return res        
```