### 解题思路
第一步：计算减去个个位数后的剩余值： n = n - 9 * 10^0 - 9 * 10^1 - 9 * 10^(n - 1)
第二步：num = n / base + Math.pow(10, base - 1)，然后在进行求余 num % base找到对应num的地方

### 代码

```java
class Solution {

    /**
    * 有个计算公式
    **/
     public int findNthDigit(int n) {
        // 判断是否个位数
        if (n < 10) {
            return n;
        }
        // 第一步：计算减去个个位数后的剩余值： n = n - 9 * 10^0 - 9 * 10^1 - 9 * 10^(n - 1)
        int base = 1;
        long count = 0;  //计算有多少位,测试的时候发现有个1e9的用例，这个用例会导致count越界
        while (true) {
            count = base == 1 ? 10 : (long) (Math.pow(10, base - 1) * 9 * base);
            if (n < count) break;
            n -= count;
            base++;
        }
        // // 第二步：num = n / base + Math.pow(10, base - 1)，然后在进行求余 num % base找到对应num的地方，
        int num = (int) (n / base + Math.pow(10, base - 1));
        return String.valueOf(num).charAt(n % base) - '0';
    }

}
```