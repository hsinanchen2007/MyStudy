### 解题思路
但是这种办法似乎用时还比较长，感觉时间复杂度是 O(n)  为什么还用了57ms

### 代码

```java
class Solution {
    public String licenseKeyFormatting(String S, int K) {
        S = S.replaceAll("-", "").toUpperCase();
        StringBuilder sb = new StringBuilder();
        int i = S.length();
        while (i >= 0){
            if(i - K <= 0){
                sb.insert(0, S.substring(0, i));
                break;
            }
            sb.insert(0, "-" + S.substring(i - K, i));
            i -= K;
        }
        return sb.toString();
    }
}
```