### 解题思路
我们首先来看一种最简单的情况，当只有两个数字时，例如23，我们是将2中的a、b、c和3中的d、e、f分别拆开，并进行组合，共有九中组合方式：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]。
当一共有三个数字时，例如234，可以将23看成一个部分，4看做一个部分，分别将["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]与g、h、i组合，一共有27种组合方式，即为234的输出结果
因此，这道题我们可以这样理解——将一个组合中的前两个数字进行组合，得到结果；再将这个结果与第三个数字组合，得到前三个数的结果；再将前三个数的结果与第四个数进行组合……以此类推，得到最终解。

备注：这种解法如果不在外面定义一个函数，而直接在主体部分作几重循环，代码会更加精简，最后的运行时间和内存消耗也可以继续优化。这里为了方便解读，故单独拿出来写了一个函数
### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        #首先，将电话号码转换成字典
        lie={'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
        #如果是空，则输出空数组
        if digits=='':
            return []
        #定义一个函数，拼接前n个已经组合完成的数字与第n+1个未拼接的数字
        def pinjie(num1:[],num2:str):
            a=[]
            for i in num1:
                for j in num2:
                    s=i+j
                    a.append(s)
            return a
        #下面开始正式的拼接，首先初始化输出结果为空数组，并将初始化第一个数字为数组形式
        b=[]
        for i in lie[digits[0]]:
            b.append(i)
        #调用已经写好的函数，输出结果
        for i in range(1,len(digits)):
            k=lie[digits[i]]
            b=pinjie(b,k)
        return b

```