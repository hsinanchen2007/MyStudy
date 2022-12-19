1. 对于任意一个数，如果是2的N次方，则1的个数是1。
2. 如果一个数x满足 X>2的N次方  X<2的(N+1)次方 则满足a[x] = a[x-2的N]+1
代码如下：
```
 public int[] countBits(int num) {
        int[] results = new int[num + 1];
        int m = 1;
        for (int i = 1; i <= num; i++) {
            if (i == m * 2) {
                m = m * 2;
                results[i] = 1;
            } else {
                results[i] = results[i - m] + 1;
            }
        }
        return results;
    }
```