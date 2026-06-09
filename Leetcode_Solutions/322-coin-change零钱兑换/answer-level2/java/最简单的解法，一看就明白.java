```
class Solution {
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        AtomicInteger count = new AtomicInteger(-1);
        AtomicInteger size = new AtomicInteger(0);
        backtrack(amount, coins, coins.length - 1, size, count);
        return count.get();
    }

    void backtrack(int amount, int[] coins, int max, AtomicInteger size, AtomicInteger count) {
        if (amount == 0) {
            if (count.get() == -1 || count.get() > size.get()) {
                count.set(size.get());
            }
        } else {
            for (int i = max; i>=0;i--) {
                if (count.get() != -1) {
                    if (size.get()>=count.get()) {
                        break;
                    } else if (amount/coins[i] >= count.get() - size.get()) {
                        break;
                    } 
                }
                if (coins[i] > amount) {
                    continue;
                }
                size.incrementAndGet();
                backtrack(amount - coins[i],  coins, i, size, count);
                size.decrementAndGet();
            }
        }
    }
}
```
