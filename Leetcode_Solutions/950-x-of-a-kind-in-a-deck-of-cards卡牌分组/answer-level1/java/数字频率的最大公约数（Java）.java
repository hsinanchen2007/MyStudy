### 最大公约数

- 题意简述为：每组都同点数，每组能至少两张吗？
  - 允许多组同点数
  - 允许组内有奇数张
- 求每个数字的频率
- 可不对频率排序，直接求频率之间的最大公约数
- 判断是否所有的频率都能够整除最大公约数
  - 存在非 `1` 的最大公约数

```java
public boolean hasGroupsSizeX(int[] deck) {
    // base case
    if (deck.length < 2) return false;

    // 统计频率
    int[] freq = new int[10000];
    for (int num : deck) freq[num]++;

    // 默认最大公约数为第一个数字的
    int gcd = freq[deck[0]];
    for (int f : freq) {
        if (f == 0) continue;

        // 不断求最大公约数并更新
        gcd = gcd(gcd, f);

        // 没有最大公约数
        if (gcd == 1) return false;
    }
    return true;
}

// 求两数的最大公约数
private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

### 复杂度分析

- 时间复杂度 $O(log(k))$，$k$ 为数组元素范围
- 空间复杂度 $O(1)$
  - 频率数组 `freq` 的开销
  - 可考虑先遍历数组，求出最大值，再决定 `freq` 的开销
- Tip: **$O(1)$ 未必就比 $O(n)$ 要小喔**
  - `n` 最大牌数也不超过 10000，但此代码中固定最大遍历、开销都是 10000
- 若牌数超过 10000，则复杂度分析应使用官方的 $O(nlog(k))$