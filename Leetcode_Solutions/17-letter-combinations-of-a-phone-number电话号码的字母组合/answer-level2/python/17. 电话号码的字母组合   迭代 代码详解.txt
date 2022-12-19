### 代码

```python
class Solution(object):
    #初始化
    def __init__(self):
        self.nums = ['abc','def','ghi','jkl','mno','pqrs','tuv','wxyz']

    def letterCombinations(self, digits):
        ans = []
        ls = len(digits)
        temp = []
        i = 0
        #digits 的长度有多少就要进行几重循环的组合相加
        #循环推出条件就是完成所有循环次数
        while ls != 0:
            #初始时，中间存储变量为空，为了可以和字符相加，需要使 t = ''
            if not temp:
                t = ''
                #digits[0]的组合情况
                for c in self.nums[int(digits[i])-2]:
                    temp += [t+c]
            else:
                for t in temp:
                    for c in self.nums[int(digits[i])-2]:
                        temp += [t+c]
                    #因为temp不断在更新长度，若没有跳出条件会一直进行下去，死循环
                    if temp.index(t) == lt - 1:
                        break
            lt = len(temp)
            #每执行完一个字符,ls -= 1
            ls -= 1
            #执行digits的下一个字符
            i += 1
        #最后得到的temp将过程组合情况都包含进去了，而我们要的是最后一次处理得到的结果，为处理方便，逆序
        temp = temp[::-1]
        #该部分求出我们最后要的列表长度
        l = 1
        for d in digits:
            l *= len(self.nums[int(d)-2])
        ans = temp[:l]
        return ans[::-1]
                
```