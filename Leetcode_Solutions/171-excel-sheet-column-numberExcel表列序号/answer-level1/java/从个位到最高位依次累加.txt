26进制， i从低位个位开始累加，当前i位的值乘以26的i次方。

比如 ZMK = ('K'-'A'+1)*26^0 + ('M'-'A'+1)*26^1 + ('Z'-'A'+1)*26^2

```
class Solution {
    public int titleToNumber(String s) {
        int result = 0;
        for(int i = s.length()-1; i>=0; i--) {
            result+=(s.charAt(i)+1-'A')*Math.pow(26, (s.length()-1 - i));
        }
        return result;
    }
}
```


