1 无需if,直接遍历是9变0，否则加1 return
```
def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        for i in range(len(digits) - 1, -1, -1):#==for i in range(1, len(digits)+1) digits[-i]
            if digits[i] != 9:
                digits[i] += 1
                return digits
            digits[i] = 0
        digits.insert(0, 1)
        return digits
```

2 str list int之间的转化
`return [int(x) for x in str(int(''.join(str(s) for s in digits))+1)]`
3 先用10次幂求和+1，再基于str int list转化
```
sum = 0
for i in range(1, len(digits)+1):
    sum += digits[-i]*10**(i-1)
return [int(x) for x in str(sum+1)]
```
4 在3的基础上，换了求和公式
```
for i in digits:
        sum = sum*10 + i
```
5 递归的方式做，比较复杂耗内存
```
def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        def addOne(digits, index):
            if index == -1:
                digits.insert(0, 1)
                return digits
            digits[index] += 1
            if digits[index]==10:
                digits[index] = 0
                return addOne(digits, index-1)
            return digits
        return addOne(digits, len(digits)-1)
```
