### 解题思路
![加1-66.png](https://pic.leetcode-cn.com/77b42307752dfddef8bcbb1d82bbf3034cb140a58410bf436d314e794ee58a36-%E5%8A%A01-66.png)

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        for(int i = digits.length-1; i >= 0; i--){ //从后向前循环
            digits[i]++;                           //从后向前每位加1
            digits[i] = digits[i] % 10;
            if(digits[i] != 0){               //若该位加1不等于10 直接输出
                return digits;
            }
        }                                         //若直到循环结束也未找到不为0的位
        digits = new int[digits.length + 1];  //在前面开辟一块新空间 
        digits[0] = 1;                        //把第一位置1
        return digits;
    }
}
```