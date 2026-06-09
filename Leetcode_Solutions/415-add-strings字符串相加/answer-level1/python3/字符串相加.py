### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        short_str = min([num1,num2],key = len)
        long_str = num1 if short_str == num2 else num2
        short_str = short_str.rjust(len(long_str),'0')
        short_list = list(short_str)
        long_list = list(long_str)
        del short_str
        del long_str
        jinwei = 0
        for i in range(1,len(long_list)+1):
            sum_num =int(short_list[-i]) + int(long_list[-i]) + jinwei
            if sum_num >= 10:
                short_list[-i] = str(sum_num%10)
                jinwei = sum_num // 10
            else:
                short_list[-i] = str(sum_num)
                jinwei = 0
        if jinwei != 0:
            short_list[0:0] = [str(jinwei)]
        print(short_list)
        return ''.join(short_list[:])

```