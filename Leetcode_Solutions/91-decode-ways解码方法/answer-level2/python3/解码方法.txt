### 解题思路
我的思路：
本来是想练动态规划, 但想不出来, 写着写着就变成了遍历...
由于考虑了数字0, 代码写的有点杂乱.说说主要的思路：
若字符串都在'26'以内, 比如'12141221',那么它的长度n决定了解码方法的总数,也就是第n个斐波那契数(可以自己验算一下);
若字符串中不含0且"超出"了'26', 比如'1234871121', 编码的总数即fib(3)*fib(4) = 15,因为'12','23'都小于'27'但是'34'会大于'26', 因此长度只记录为'123'的长度;后部分的'1121'也是同理.
若字符串含'0', 那问题就开始复杂了= =, 也是我代码看起来有点杂乱的原因.若s[0]为0或者s中有超过'26'的且末尾为'0'的, 比如'30' --> 则直接返回0. 若小于'27'且末尾为'0'比如'20',则长度数不加反减1.
具体实现看代码....其中dp函数即用迭代来求第n个斐波那契数，时间复杂度为o(m)
	
整个算法的复杂度分析：                                                             
	• 时间复杂度：o(nm)，其中n为s总长度,m为分长度
	• 空间复杂度：o(k)，k为分长度的个数

### 代码

```python
class Solution:
    def numDecodings(self, s: str) -> int:
        def dp(n):
            pre = 1
            bac = 2
            if n == 1:
                return pre
            elif n == 2:
                return bac
            elif n == 0:
                return 1
            for i in range(3, n+1):
                res = pre + bac
                pre = bac
                bac = res
            return res
        if s == '' or s[0] == '0':
            return 0
        cur = 1
        lists = []
        for i in range(len(s)-1):
            if s[i:i+2] == '00':
                return 0
            elif s[i] == '0':
                cur = 1
            elif s[i:i+2] < '27':
                if s[i+1] != '0':
                    cur += 1
                else:
                    cur -= 1
                    lists.append(cur)
                    cur = 1
            elif s[i:i+2] >= '27' and s[i+1] =='0':
                return 0
            else:
                if cur > 1:
                    lists.append(cur)
                cur = 1
        lists.append(cur)
        result = 1
        for x in lists:
            result *= dp(x)
        return result


```