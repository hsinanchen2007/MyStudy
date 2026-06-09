### 解题思路
注解如代码

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        int len = str.length();
        if (len == 0) return 0;
        int i = 0;//字符串索引
        int sign = 1;//正数结果还是负数结果
        int total = 0;//最后的结果

        //跳过空字符
        while (i < len && str.charAt(i) == ' ') i++;
        //判断是正数还是负数
        if (i < len && (str.charAt(i) == '-' || str.charAt(i) == '+')) {
            sign = str.charAt(i++) == '-' ? -1 : 1;
        }
        //开始统计后面的数字
        while (i < len) {
            int val = str.charAt(i) - '0';
            if(val < 0 || val > 9) break;
            //如果Integer的最大值 / 10 < total，拿下次计算，肯定是溢出了，
            //如果Integer的最大值 / 10 = total，且最大值求余 < val，那么肯定也是溢出
            if (Integer.MAX_VALUE / 10 < total || (Integer.MAX_VALUE / 10 == total && Integer.MAX_VALUE % 10 < val)) {
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            total = total * 10 + val;
            i++;
        }
        return total * sign;
    }
}
```