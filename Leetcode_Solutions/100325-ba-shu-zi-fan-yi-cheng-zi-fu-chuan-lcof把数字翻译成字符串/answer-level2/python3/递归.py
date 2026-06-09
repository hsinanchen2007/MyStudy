### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def translateNum(self, num: int) -> int:
        num = abs(num)
        if 0<= num <=9:
            return 1 
        elif 10<=num<=25:
            return 2 
        elif 25<num<100:
            return 1 
        else:
            num_str = str(num)
            if int(num_str[:2])<=25:
                return self.translateNum(int(num_str[1:])) +self.translateNum(int(num_str[2:]))
            else:
                return self.translateNum(int(num_str[1:]))

```