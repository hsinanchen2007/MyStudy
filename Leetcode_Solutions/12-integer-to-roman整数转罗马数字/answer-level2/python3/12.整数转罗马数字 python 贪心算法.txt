### 解题思路
贪心算法：即使得某个状态以前的过程不会影响以后的过程。从大范围逐渐缩小返回，获取局部的最优解。
和动态规划不一样哦~~动态规划是全局最优解

贪心算法基本思路：

    建立数学模型来描述问题
    把求解的问题分成若干个子问题
    对每个子问题求解，得到子问题的局部最优解
    把子问题的解局部最优解合成原来问题的一个解


### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        # 贪心算法
        rule = (
            ('M', 1000),
            ('CM', 900), ('D', 500), ('CD', 400), ('C', 100),
            ('XC', 90), ('L', 50), ('XL', 40), ('X', 10),
            ('IX', 9), ('V', 5), ('IV', 4), ('I', 1),
        )
        result = ''


        # 法一
        
        for letter,number in rule:
            if num >= number:
                result += letter*(num//number)
                num %= number
        return result
       
 
        # 法二
        i = 0
        while i < 13:
            while num >= rule[i][1]:
                # 等于号使得罗马字符尽可能少
                result += rule[i][0]
                num -= rule[i][1]
            i += 1
        return result
        



```