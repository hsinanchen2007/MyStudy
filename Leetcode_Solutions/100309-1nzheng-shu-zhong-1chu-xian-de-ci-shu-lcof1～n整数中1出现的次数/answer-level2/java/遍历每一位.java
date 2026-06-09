### 解题思路


### 代码

```java
class Solution {
    public int countDigitOne(int n) {
        if(n < 0) {
            return -1;
        }
        if (n == 1) {
            return 1;
        }
        long digits = 1;
        int cnt = 0;
        long current = 0, pre = 0, latter = 0;
        while ((n/digits) != 0) {
            pre = n / (digits * 10);
            current = (n / digits) % 10;
            latter = n - (n / digits) * digits;
            if (current == 1) {
                cnt += pre * digits + 1 + latter; 
            }
            if(current == 0) {
                cnt += pre * digits;
            }
            if(current > 1) {
                cnt += (pre+1) * digits;
            }
            digits *= 10;
        }
        return cnt;
    }
}
```