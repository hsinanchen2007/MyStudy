```
/**
 *
 * 解题思路：
 * PS：这是一道纯粹的组合数学的问题
 * 因为每笔订单都是按“配送——收件”的顺序，所以我们只需要先把所以的订单配送顺序固定好，
 * 然后再确定收件顺序就OK了。
 * n笔订单，显然订单配送的序列共用n!种，然后我们按配送顺序从后往前确定收件顺序
 * 假设配送顺序如下：
 * 1 2 3 4 ... n-1 n
 * 显然订单n的收件只能放在n之后，所以只有1种排列，插入收件n之后：
 * 1 2 ... n-1 n 收件n
 * 订单n-1的收件则有3种，以此类推，n-3 5种，n-k (2k-1)种
 * 而每种收件的插入都是相互独立的，所以共(2n-1)!!种
 * 所以总的序列数为(n! * (2n-1)!!);
 *
 * create by chris https://github.com/noyo/
 */

public class Problem1359 {

    public int countOrders(int n) {
        int mod = (int) (1e9 + 7);
        long res = 1;
        for (int i = 1; i <= n; i++) {
            res = (res * i) % mod;
            res = (res * (2 * i - 1)) % mod;
        }

        return (int) res;
    }

}

```
