### 解题思路
看到很多答案都是把每种情况存了起来使用贪心算法，虽然容易懂，但是觉得写得有点难受，针对这种数据比较少的还好，但是如果情况比较多感觉通用性较差。于是想写一种更通用性的方法（个人想法23333）。但是貌似复杂度高很多（毕竟没有列举，而是针对通用性）。思想就是因为个位，十位，百位的转换方法都是一样的，只是变了roman字符，所以可以合并到一起来。


### 代码

```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        int_num = [1000, 100, 10, 1]
        roman_num = ["M", "D", "C", "L", "X", "V", "I"]
        roman = []
        result = ""
        for i in range(len(int_num)):  #得到相应的千百十个位上的数字
            roman.append(int(num/int_num[i]))
            num = num % int_num[i]
        for j in range(len(roman)): #注意roman_num中2*j的位置恰好是当前的roman数字的位置。然后针对不同情况添加roman数字
            if roman[j] >= 0 and roman[j] <=3:
                result += roman_num[2*j] * roman[j]
            elif roman[j] == 4:
                result += roman_num[2*j] + roman_num[2*j-1]
            elif roman[j] > 4 and roman[j] < 9:
                result += roman_num[2*j-1] + roman_num[2*j] * (roman[j] - 5)
            elif roman[j] == 9:
                result += roman_num[2*j] + roman_num[2*j-2]
        return result
```