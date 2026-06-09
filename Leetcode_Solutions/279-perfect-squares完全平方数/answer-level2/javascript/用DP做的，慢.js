### 解题思路
![image.png](https://pic.leetcode-cn.com/1bd85352b1251a624ae90adf955f4c02e94a5b91fd014215689c56f612a75d9e-image.png)

在“队列”教程中出现的这道题，似乎应该用队列做，但我想不出来怎么个BFS，只能用dp做了，慢的令人发指，我已经用map存储历史数据了。。。不然铁定TLE了。

发了这篇题解，让我去翻答案。。。。

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {
    let sqr = [],
        dpMap = new Map();

    const isSqr = num => {
        if (sqr.includes(num)) return true;
        for (let i = 1; i <= num / i; i++) {
            let s = i * i;
            if (!sqr.includes(s)) sqr.push(s);
            if (s === num) {
                return true;
            }
        }
        return false;
    }

    const dp = n => {
        if (isSqr(n)) return 1;
        let prev = Number.MAX_SAFE_INTEGER;
        let idx = sqr.findIndex(val => { return val > n }) != -1 ? sqr.findIndex(val => { return val > n }) - 1 : sqr.length - 1
        for (let i = idx; i >= 0; i--) {
            prev = Math.min(prev, dpMap.has(n - sqr[i]) ? dpMap.get(n - sqr[i]) : dp(n - sqr[i]));
        }

        if (!dpMap.has(n)) dpMap.set(n, prev + 1);
        return prev + 1;
    }

    return dp(n);
};
```