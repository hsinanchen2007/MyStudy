### 代码

```java
class Solution {
    // 十进制转其他进制：num/7取余
    public String convertToBase7(int num) {
        StringBuffer sb = new StringBuffer();
        boolean flag = false;
        if (num < 0) {
            num = -num;
            flag = true;
        }
        while(num >= 7) {
            int res = num % 7;
            num = num / 7;
            sb.append(res);
        }
        sb.append(num);
        if (flag) sb.append("-");
        sb.reverse();
        return sb.toString();
    }
}
```