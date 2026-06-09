### 解题思路
直接解答此题很简单，本题原意考察在n为超大值的情况下，int类型不能满足输出，需要采用字符串的方式。因为leetcode的提交方式，导致本题直接解答即可。


## 代码


### 直接解答：
```
class Solution:
'''执行用时 :128 ms, 在所有 Python3 提交中击败了12.90%的用户
   内存消耗 :25 MB, 在所有 Python3 提交中击败了100.00%的用户'''
    def printNumbers(self, n: int) -> List[int]:
        num = 1
        for i in range(n):
            num *= 10
        ans = [] 
        for i in range (1,num):
            ans.append(i)
        return ans
```



### 使用字符串代替数字：
##### 相当于0-9的数字字符进行排列组合，在输出时去除首位的0字符
```
class Solution:
'''执行用时 :348 ms, 在所有 Python3 提交中击败了6.45%的用户
   内存消耗 :25 MB, 在所有 Python3 提交中击败了100.00%的用户'''
    def printNumbers(self, n: int) -> List[int]:
        number = []
        ans = []
        for i in range(n):
            number.append('')
        for i in range(10):
            number[0] = str(i)
            self.getNumbers(number, n, 0, ans)
        return ans

    def getNumbers(self, number, n, index, ans):
        if index == n-1:
            begin0 = True
            xx = ''
            for j in range(n):
                if begin0 and int(number[j]) != 0:
                    begin0 = False
                if begin0 is False :
                    xx += number[j]
            # 为了满足leetcode 此处还是进行了int类型的转换
            if xx != '':
                ans.append(int(xx))
            return

        for i in range(10):
            number[index + 1] = str(i)
            self.getNumbers(number, n, index + 1,ans)
```

