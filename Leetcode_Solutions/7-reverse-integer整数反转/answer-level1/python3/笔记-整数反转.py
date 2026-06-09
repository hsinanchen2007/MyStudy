使用最简单的思路，规避了Python取余和除法的坑，以及题目的反转数的范围约束。代码思路简单，仅供参考
```
class Solution:
    def reverse(self, x: int) -> int:
        result_list = []
        i = 0
        if x<0:
            num = (-1)*x
        else:
            num = x
        while num//10:
            i += 1
            result_list.append(num % 10)
            num = num//10
        result_list.append(num % 10)
        i += 1
        # print(result_list, i)
        result = 0
        for j in range(i):
            result += result_list[j]*pow(10, i-1-j)
        if x<0:
            result = result*(-1)
        if result<=pow(2, 31)-1 and result>=(-1)*pow(2, 31):
            return result
        else:
            return 0
            
```
