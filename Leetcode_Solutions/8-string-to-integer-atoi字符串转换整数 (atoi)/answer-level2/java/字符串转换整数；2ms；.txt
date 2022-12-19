### 解题思路
根据题意, 遍历该字符串，判断第一个字符是否为+，-，+，-只能出现在字符串的首位，当遇到不为0~9的数时就停止遍历，并定义number来记录最后获取的数，并判断该数值是否超出整数范围。

### 代码
```python []
INT_MAX = 2 ** 31 - 1
INT_MIN = -2 ** 31

class Solution:
    def myAtoi(self, str: str) -> int:
        str = str.strip()
        number = 0
        flag = False
        first = True
        for elem in str:
            if elem == '-' and first == True:
                flag = True
                first = False
                continue
            elif elem == '+' and first == True:
                first = False
                continue
            if elem <= '9' and elem >= '0':
                number = number * 10 + int(elem)
                first = False
            else:
                break
        if flag == True:
            number = number * (-1)
            if number < INT_MIN:
                return INT_MIN
            else :
                return number
        if number > INT_MAX:
            return INT_MAX
        else :
            return number                                      
```

```java []
class Solution {
    public int myAtoi(String str) {
        str = str.trim();
        double number = 0; // 得到的数可能会超出范围，故定义number为double类型
        boolean flag = false; // 是否为负数
        boolean first = true; // 判断第一个字符是否为+，-
        for (int i = 0; i < str.length(); i++) {
            Character c = str.charAt(i);
            if(c == '-' && first == true) {
                flag = true;
                first = false;
                continue;
            } else if (c == '+' && first == true) {
                first = false;
                continue;
            }
            if(c <= '9' && c >= '0') {
                number = number * 10 + (c - 48);
                first = false;
            } else {
                break;
            }
        }
        if(flag == true) {
            number = number * (-1);
            if(number < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            } else {
                return (int)number;
            }
        }
        if(number > Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        } else {
            return (int) number;
        }
    }
}
```