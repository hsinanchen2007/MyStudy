### 代码

```java
class Solution {
    public int countDigitOne(int n) {
        int o = 0, a = 1, b = 1;
        while(n > 0){
            o += (n + 8) / 10 * a;
            if(n % 10 == 1) o += b;
            b += n % 10 * a;
            a *= 10;
            n /= 10;
        }
        return o;
    }
}


```