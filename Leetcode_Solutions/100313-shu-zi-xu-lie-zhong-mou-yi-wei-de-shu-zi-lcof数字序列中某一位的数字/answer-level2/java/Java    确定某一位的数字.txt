### 解题思路
和书上描述的思路一样。
例子：1001 
// 例如第1001位的数字是多少？
// 序列前10个一位数，显然不满足，则跳过：1001 - 10 = 91
// 序列前90个两位数（10 - 99）即90 * 2 = 180位，显然不满足，则跳过：991 - 90 * 2 = 811
// 序列前900个三位数（100 - 999即900 * 3 = 2700位），显然满足，则find：811 / 3 = 270 - 1
// 因此需要走过270个三位数，然后再往后走一位，即100+270即370，即370的中间一位，即返回7

### 代码

```java
class Solution {
    public int findNthDigit(int n) {
        // 判断是否个位数
        if (n < 10) {
            return n;
        }

        // 第一步：计算减去个位数后的剩余值： n = n - 9 * 10^0 - 9 * 10^1 - 9 * 10^(n - 1)
        int base = 1;
        long count = 0;  //计算有多少位,测试的时候发现有个1e9的用例，这个用例会导致count越界
        while (true) {
            count = base == 1 ? 10 : (long) (Math.pow(10, base - 1) * 9 * base);
            if (n < count) break;
            n -= count;
            base++;
        }
        
        // 第二步：num = n / base + Math.pow(10, base - 1)，然后在进行求余 num % base找到对应num的地方，
        int num = (int) (n / base + Math.pow(10, base - 1));
        return String.valueOf(num).charAt(n % base) - '0';
    }
}
```