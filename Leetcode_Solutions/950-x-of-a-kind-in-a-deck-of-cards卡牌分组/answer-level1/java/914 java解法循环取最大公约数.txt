### 解题思路
先统计每个元素出现次数，然后依次计算出现次数的最大公约数，若为1，返回false，证明无法分组。
例如:[1,1,1,1,2,2,2,2,2,2]
freq[1] = 4
freq[2] = 6
最大公约数为2，可以分为2个一组，[[1,1],[1,1],[2,2],[2,2],[2,2]]，返回true。

例如：[0,0,1,1,1,1,1,1,2,2,2]
freq[0] = 2
freq[1] = 6
freq[2] = 3
gcd(2, 6) -> 2
gcd(2, 3) -> 1 表示不能分组，返回false。

### 代码

```java
class Solution {
    /**
     * 执行用时 :3 ms, 84.46%
     * 内存消耗 :41.6 MB, 5.64%
     */
    public boolean hasGroupsSizeX(int[] deck) {
        if (deck == null || deck.length < 2)
            return false;
        int[] freq = new int[10000];
        for (int n : deck)
            freq[n]++;
        int X = freq[deck[0]];
        for (int f : freq) {
            if (f == 0)
                continue;
            X = gcd(X, f);
            if (X == 1 || f % X != 0 )
                return false;
        }
        return true;
    }

    //求最大公约数
    private int gcd(int a, int b) {
        while(a != 0) {
            int tmp = a;
            a = b%a;
            b = tmp;
        }
        return b;
    }

}
```