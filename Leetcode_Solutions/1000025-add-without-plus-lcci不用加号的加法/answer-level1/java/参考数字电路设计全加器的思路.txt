## 题解代码
``` java
class Solution {
    public int add(int a, int b) {
        int ans = a^b;//不含进位
        int carry= (a&b) <<1;
        while (carry != 0) {
            int tmp = ans;
            ans = ans^carry;
            carry = (tmp&carry) << 1;
        }
        return ans;
    }
}
```
## 解题思路
1. 进行不含进位的加法的运算,即异或运算,结果记为ans
2. 每一位上的进位凑成一个数,记为carry,显然carry = (a&b) <<1
3. 如果carry为0,则答案为ans;如果carry不为0,则答案为ans+carry,为了完成新出现的加法运算,重复过程1,2