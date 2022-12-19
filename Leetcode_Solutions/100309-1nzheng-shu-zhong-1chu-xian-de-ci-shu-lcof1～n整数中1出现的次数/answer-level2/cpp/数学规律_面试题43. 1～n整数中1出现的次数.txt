### 解题思路
    /*
     * 数学规律 O(log<10>n)
     *
     * 每10个数，个位的1就会出现一次，每100个数，十位的1就会出现一次。
     * 依此递推公式 (n/(i*10))*i
     *
     * 同时，如果十位上的数是1，则最后1的数量要加上 x+1，其中x是个位上的数值。
     * 如果十位上的数大于1，则十位上为1的所有的数都符合要求，次数最后1的数量要加10。
     * 依此递推公式 std::min(std::max((n mod (i*10)) - i + 1, 0), i)
     *
     * 所以最后1的总数公式是：
     * (n / (i * 10)) * i + std::min(std::max((n mod (i * 10)) - i + 1, 0), i)
     * */
### 代码

```cpp
int Solution43::countDigitOne(int n) {
    int counter = 0;

    // 通过规律公式计算
    for (long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;
        counter += (n / divider) * i + std::min(std::max(n % divider - i + 1, 0LL), i);
    }

    return counter;
}
```