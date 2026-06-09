### 解题思路
 - 排序；
 - 根据 f(s) = f(s - k) + 1; 递归深度遍历找出最小值 
![image.png](https://pic.leetcode-cn.com/10e9ef4032eee3e94a48d73aeb194966e358ee3c5bbe33208b9200a9ef0b898a-image.png)

### 代码

```javascript
/**
 * @param {number[]} coins
 * @param {number} amount
 * @return {number}
 */
var coinChange = function(coins, amount) {
    // 先排序；从大到小
    coins.sort((a, b) => b - a);
    let cache = {};
    let min = coins[coins.length - 1];
    // 通过领取中的最小值，计算一个大致的最多次数
    let max = Math.ceil(amount / min);
    function self(coins, amount, start = 0) {
        if (amount < 0) {
            return -1;
        }
        if (amount === 0) {
            return start;
        }
        // 取缓存
        if (cache[amount] !== undefined) {
            return cache[amount];
        }
        let count = start;
        let res = max;
        // 放标志位，如果标志位改变，那么肯定有计算出结果的
        let change = false;
        for (let i = 0; i < coins.length; i++) {
            let next = amount - coins[i];
            if (next < 0) {
                continue;
            }
            // 递归算出子集
            const now = self(coins, next, count);
            // 如果now没减小，说明有解，能兑换；
            if (now >= count) {
                change = true;
                res = Math.min(res, now + 1);
            }
        }
        // 存缓存；
        cache[amount] =  change ? res : -1;
        return cache[amount];
    }

    return self(coins, amount, 0);
};
```