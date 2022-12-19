```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        sum1 = 0
        class1 = 0
        for i in num1[::-1]:
            temp = 0
            add = 0
            class2 = 0
            for j in num2[::-1]:
                i_int = ord(i) - ord("0")
                j_int = ord(j) - ord("0")
                t = i_int * j_int + add
                add = t // 10
                res = t % 10
                temp += res * (10 ** (class2 + class1))
                class2 += 1
            if add > 0:
                temp += add * (10 ** (class2 + class1))
            class1 += 1
            print(temp)
            sum1 += temp
        return str(sum1)
```
