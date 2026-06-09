### 解题思路
看了几个题解，我感觉组合数公式是思路也还行啊 时间和空间都击败90%+ 哇


### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        if n<=0:
            return 0
        if n==1:
            return 1
        buf_2 = n//2
        buf_1 = n%2
        def calculate_choose_m_of_n(m,n):
            numerator_list = list(range(n-m+1,n+1))
            denominator_list = list(range(1,m+1))

            quotient=1
            numerator_index = len(numerator_list)-1
            while(len(denominator_list)>=1):
                if quotient%denominator_list[0]!=0:

                    quotient *= numerator_list[numerator_index]
                    numerator_index -= 1 #指向下一个个可以添加的被除数
                else:
                    quotient = quotient//(denominator_list.pop(0))
            #退出时 还有剩余被除数们
            for i in range(0,numerator_index+1):
                quotient *= numerator_list[i]
            return quotient
        count = 0
        while(buf_2>=0):
            count += calculate_choose_m_of_n(buf_2,buf_2+buf_1)
            buf_2 -= 1
            buf_1 += 2
        return count
```