### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int reverse(int x) {
        int res = 0;
        while(x != 0) {
            int pop = x % 10; //取原整数的个位数
            if(res > Integer.MAX_VALUE / 10 || (res == Integer.MAX_VALUE / 10 && pop > 7)) {
                return 0;
            }
            if (res < Integer.MIN_VALUE / 10 || (res == Integer.MIN_VALUE / 10 && pop < -8)) {
                 return 0;
            }
            res = res * 10 + pop;
            x /= 10;
        }
        return res;
    }
}
```