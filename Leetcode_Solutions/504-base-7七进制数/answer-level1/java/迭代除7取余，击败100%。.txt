### 解题思路
基本思路就是迭代除7取余，存到一个StringBuilder里，最后反转即可。
对于负数，直接先取正处理，然后加上负号即可。

### 代码

```java
class Solution {
    public String convertToBase7(int num) {
        String ans = "";
        if (num < 0) {
            num = 0 - num;
            ans += "-";
        };
        StringBuilder sb = new StringBuilder();
        do {
            int mod = num % 7;
            sb.append((char)('0'+mod));
            num = num / 7;
        } while (num > 0);
        ans += sb.reverse().toString();
        return ans;

    }
}
```