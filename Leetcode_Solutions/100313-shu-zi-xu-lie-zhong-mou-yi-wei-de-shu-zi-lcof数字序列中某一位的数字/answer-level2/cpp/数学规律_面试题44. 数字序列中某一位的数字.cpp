### 解题思路
    /*
     * 数学规律
     *
     * 通过观察有以下规律：
     * 123456789             9个数     9*1位数字
     * 10 11 12 ... 98 99    90个数    90*2位数字
     * 100 101 ... 998 999   900个数   900*3位数字
     * ......
     *
     * 对于第n位对应的数字，定义该数字对应的数为number，以下三步计算：
     * 1. 找到该数字对应的数的位数digits;
     * 2. 确定对应的数的数值为number；
     * 3. 确定返回值是number的哪一位数字idx。
     *
     * 例如：n = 365
     * 1. 通过计算知n的位数为：digits = 3，而计算后n = 365 - 9 + 90 * 2 = 176，
     *    表示number是三位数中的第176个数
     * 2. 由1知number是三位数中的第176个数，计算后number = 10^2 + 176/3 = 158
     * 3. idx是所求数字在number中的位数，当idx == 0时，表示该数字是number-1的最后一位数字。
     *    通过计算知idx = n % digits = 176 % 3 = 2，说明所求数字是number = 158的第2位数字5。
     * */
### 代码

```cpp
int findNthDigit(int n) {
    if (n < 0) {
        return -1;
    }

    int digits = 1;
    int base = 9;
    // 计算n的位数digits
    // 同时将n减去不可能的数，
    // 即原n为digits位中的第新n位数
    while (n - base * digits > 0) {
        n -= base * digits;
        base *= 10;
        digits++;
    }

    // 所求数字在number中的位数
    int idx = n % digits;
    int number = 0;

    // 当位数为0时，表示是number-1的最后一位数字
    if (idx == 0) {
        // 计算number = number - 1(概念上)
        number = std::pow(10, digits - 1) + n / digits - 1;

        // 因为是number-1的最后一位，
        // 则取个位数返回
        return number % 10;
    } else {
        number = std::pow(10, digits - 1) + n / digits;

        // 因为idx是number的中间位
        for (int i = idx; i < digits; i++) {
            number /= 10;
        }

        return number % 10;
    }
}
```