枚举从10到10^9中的每个数, 因为10到10^9的顺次数才36个.

```java
List<Integer> result = new ArrayList<>();
// 从2位数循环到9位数
for (int bit = 2; bit <= 9; bit++) {
    int b = 10 - bit; // bit位数, 最大值的最高位数. 9-bit+1
    for (int i = 1; i <= b; i++) {
        int n = 0;
        for (int j = i, k = bit; k >= 1; k--, j++) {
            n = n * 10 + j;
        }
        if (n >= low && n <= high) {
            result.add(n);
        } else if (n > high)
            return result;
    }
}
return result;
```