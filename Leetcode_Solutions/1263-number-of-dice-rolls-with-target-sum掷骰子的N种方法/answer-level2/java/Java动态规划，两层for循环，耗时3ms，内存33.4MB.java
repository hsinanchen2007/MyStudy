F(d, f, target) = sum(F(d - 1, f, target - k)), 1 <= k <= f  
F(d, f, target) 只和 F(d - 1, f, target - k)相关，所以可以用两个数组来保存这两组状态值  
F(d, f, target)的计算过程实际上是在F(d - 1, f, target - k)数组上做一个大小为f的窗口平移，计算窗口内的和  
```
class Solution {

    public int numRollsToTarget(int d, int f, int target) {
        if (d == 1) {
            return target <= f ? 1: 0;
        }
        else if (d > target || d * f < target) {
            return 0;
        }
        else if (d == target || d * f == target) {
            return 1;
        }

        int[] lastCache = new int[target + 1];
        Arrays.fill(lastCache, 1, Math.min(target, f) + 1, 1);

        int mod = (int) (Math.pow(10, 9) + 7);
        int[] curCache = new int[target + 1];
        for (int i = 2; i <= d; i++) {
            // 因为在上一次迭代计算完成后，将 lastCache 的引用赋值给了 curCache
            // 在本此迭代中curCache[i - 2], curCache[i - 1] 两项应该是0（因为 i 个骰子不可能投出总和小于 i 的情况），不置0，会导致本此迭代计算结果错误
            // i - 3 以及左边的项一定是 0 ，不用费力去置 0
            // i 及右边的项正是本此迭代计算过程中要计算的，不置 0 ，也不会影响本此迭代计算
            curCache[i - 2] = curCache[i - 1] = 0;
            for (int j = i, maxJ = Math.min(target, i * f); j <= maxJ; j++) {
                // F(d, f, target) = sum(F(d - 1, f, target - k)), 1 <= k <= f
                // curCache 的计算方式，在 lastCache 上从左往右平移一个大小为f的窗口，计算窗口内数字的和
                // curCache[j] = lastCache[j - 1 - f + 1] + lastCache[j - 1 - f + 1] + ... + lastCache[j - 1]
                //             = (lastCache[j - 1 - f] + ... + lastCache[j - 1 - 1]) + lastCache[j - 1] - lastCache[j - 1 - f]
                //             = curCache[j - 1] + lastCache[j - 1] - lastCache[j - 1 - f]
                curCache[j] = (curCache[j - 1] + lastCache[j - 1] - (j - 1 - f >= 0 ? lastCache[j - 1 - f] : 0)) % mod;
                if (curCache[j] < 0) {
                    curCache[j] += mod;
                }
            }
            // 一次迭代计算完成，交换 lastCache, curCache 引用
            int[] temp = lastCache;
            lastCache = curCache;
            curCache = temp;
        }
        return lastCache[target];
    }

}
```

