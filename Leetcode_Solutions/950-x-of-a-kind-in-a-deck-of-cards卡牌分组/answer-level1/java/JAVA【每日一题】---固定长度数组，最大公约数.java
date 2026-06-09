直观思路： 计算每个数的个数，看是否所有的数是否有公约数

```
    public boolean hasGroupsSizeX(int[] deck) {
        if (deck == null || deck.length == 0) {
            return false;
        }
        int[] vals = new int[10000];
        for (int i : deck) {
            vals[i]++;
        }

        // 遍历求最大公约数
        int val = vals[deck[0]];
        for (int i = 1; i < deck.length; i++) {
            if (vals[deck[i]] == 0) {
                continue;
            }
            val = gcd(val, vals[deck[i]]);
        }
        return val > 1;

    }

    private int gcd(int i, int j) {
        return i == 0 ? j : gcd(j % i, i);
    }
```