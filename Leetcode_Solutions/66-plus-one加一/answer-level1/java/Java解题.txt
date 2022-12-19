### 解题思路
考虑两种加法情况：
1.非数字9加1；
2.数字9加1；

特殊情况，形如9,99,999的数组。

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        for(int i=digits.length-1;i>=0;i--){
            digits[i]++;
            digits[i] = digits[i]%10;
            if(digits[i]!=0) return digits;
        }
        digits = new int[digits.length+1];
        digits[0] = 1;
        return digits;
    }
}
```