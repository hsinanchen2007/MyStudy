### 解题思路
本题为**基础回文数**算法

一开始要进行合法判断，将不符合回文数的给排除

接下来定义反转变量来保存翻转后的回文数

再保存给定的x值，用num来代替进行运算，之后再将一开始给的x和反转后的值进行比较输出true or false。

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)){//若x为负数或者个位是0
            return false;
        }
        
        int reversed = 0;//定义反转后的回文数
        int num = x;//事先保存x的值，之后只需num进行运算
        while(num != 0){
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return x == reversed;//拿给定的X和反转后的回文数进行比较
    }
}
```