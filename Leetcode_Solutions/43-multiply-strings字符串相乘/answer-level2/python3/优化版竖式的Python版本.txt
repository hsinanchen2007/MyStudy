本文是解题中的优化竖式版本的Python实现，也就是下图的这个思路。供大家参考。
![image.png](https://pic.leetcode-cn.com/0499f6e5d1094a841f6f35ea012cb9dd0d258395c2fc253f69f333ce4680d3d3-image.png)

```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0':
            return '0'

        N1 = len(num1) - 1
        N2 = len(num2) - 1
        tmp = N2
        res = [0 for _ in range(N1+N2+2)]
        while N1>=0:
            while N2>=0:
                middle_res = res[N1+N2+1] + int(num1[N1])*int(num2[N2])
                geweishu = middle_res%10
                shiweishu = middle_res//10
                res[N1+N2+1] = geweishu
                res[N1+N2] += shiweishu
                N2 -= 1
            N1 -= 1
            N2 = tmp

        print(res)
        if res[0] == 0:
            res = res[1:]
        return ''.join(str(i) for i in res)

```
