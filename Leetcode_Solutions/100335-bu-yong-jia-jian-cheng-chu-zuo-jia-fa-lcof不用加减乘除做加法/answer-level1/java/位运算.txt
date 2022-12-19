### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int add(int a, int b) {
        //先计算异或
        int noCarryPlus = a ^ b;
        //与运算并左移一位，因为进位是进在高一位
        int carry = a & b;
        carry = carry<<1;
        //循环进位，直到为0
        while(carry != 0){
            int tmpNoCarryPlus = noCarryPlus ^ carry;
            carry = noCarryPlus & carry;
            carry = carry<<1;
            noCarryPlus = tmpNoCarryPlus;
        }
        return noCarryPlus;
    }
}
```