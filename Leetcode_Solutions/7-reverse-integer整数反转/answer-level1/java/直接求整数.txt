### 解题思路
先求最高位数，再求反转后的整数值。

### 代码

```java
class Solution {
    public int reverse(int x) {
        boolean isNegative = x < 0;
        if(isNegative){
            x = -x;
        }
        int pos = 0;
        int temp = x;
        while(temp != 0) {
            pos ++;
            temp /= 10;
        }
        int curPos = 0; 
        long ans = 0;
        while(x != 0) {
            ans += (x % 10) * (Math.pow(10, (pos - curPos - 1)) );
            curPos ++;
            x /= 10;
        }

        if(isNegative) {
            ans = - ans;
        }

        if(ans > Math.pow(2, 31) - 1 || ans < -Math.pow(2,31)) {
            ans = 0;
        }
        return (int)ans;
    }
}
```