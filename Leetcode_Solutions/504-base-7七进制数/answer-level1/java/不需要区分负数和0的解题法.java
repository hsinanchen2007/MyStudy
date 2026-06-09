缺点是用了 Java 自带的 `Math.pow()` 来计算次方, 走捷径了

```
class Solution {
    // 递归计数
    long count = 0;
    // 输出结果
    long result = 0;
    public String convertToBase7(int num) {
        // 积
        int quotient = num / 7;
        // 余数
        int reminder = num % 7;
        result +=  (reminder * (Math.pow(10, count)));
        if (quotient == 0) {
            return Long.toString(result);
        }

        count ++;
        // 递归
        convertToBase7(quotient);
        
        return Long.toString(result);
    }
}
```