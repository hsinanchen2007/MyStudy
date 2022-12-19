第一次写题解分享一下思路，因为我觉得动态规划方法里创建目标值大小的数组过于冗余。
全文字，见谅。
# **人为拼硬币面值时的思路**
1. 先取最大面值的 coin，凑到不能再凑(即再凑一个最大面值硬币会超过目标值).
2. 取第二大面值的 coin，同理凑到不能再凑
3. 以此类推，直到有解or不可求解

- 假设有coin面值[a, b, c, d]，a < b < c < d
- 若目标值 tar 经过上述 凑到不能再凑的步骤后，发现已用 3枚a，4枚b，5枚c，2枚d，再填一枚a都会超过目标值
- 此时则拿走一枚 b，尝试用硬币a添加，凑到不能再凑，若达不到要求则再拿走一枚b，重复该过程。
- 当把4枚硬币b都拿走了依然不能满足要求，则开始拿走一枚硬币c，此时要先拿b凑到不能再凑，再凑a......如此类推

一般在DFS思想中该过程是 能取d,就取一个d,一个一个取，先把d取到不能再加，一次迭代只取一个值，重复取d的过程不必要，题解要求最小数量硬币，因此直接拿走最多能拿走的当前面值。
- 提高该DFS效率的方法是 先直接取 tar / d 个面值为d的硬币，剩余面值就变成 tar - d * (tar / d)
- DFS回溯回来时，拿走一个面值d的硬币，再接着进行DFS过程

```c++
class Solution {
private:
    vector<int> coins;
    int res = INT_MAX;
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0 || coins.size() == 0) return 0;
        sort(coins.begin(), coins.end());
        this->coins = coins;
        func(amount, 0, coins.size() - 1);
        if (res == INT_MAX) return -1;
        return res;
    }
    void func(int amount, int cnt, int index) {
        if (index < 0) return;
        if (amount % coins[index] == 0) {
            res = min(res, cnt + amount / coins[index]);
            return;
        }
        int i = amount / coins[index];
        if (cnt + i >= res - 1) return;//无更优解，剪枝回溯
        for (; i >= 0; --i) {
            func(amount - i * coins[index], cnt + i, index - 1);
        }
    }
};
```