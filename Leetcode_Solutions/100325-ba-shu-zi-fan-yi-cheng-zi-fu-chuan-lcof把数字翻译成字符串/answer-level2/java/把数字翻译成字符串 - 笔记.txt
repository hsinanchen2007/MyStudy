### 解题思路
用递归地方式，每次取最低的两位进行比较处理

### 代码

```java
class Solution {

    /**
    * 借鉴题解一位大佬的递归写法
    **/
    public int translateNum(int num) {
        // 如果num小于等于9，那就只有一位了
        if (num <= 9) {
            return 1;
        }

        // 取他的最低两位，%100 取余即可
        int tmp = num % 100;
        // 超出范围，则代表只是个位数，直接把个位数移除掉（相除即可砍掉最低未）
        if (tmp <= 9 || tmp >= 26) {
            return translateNum(num / 10);
        } else {
            // 非上面的，说明存在两种情况。直接把个位数、十位数 两个移除掉
            return translateNum(num / 10) + translateNum(num / 100);
        }
    }
}
```