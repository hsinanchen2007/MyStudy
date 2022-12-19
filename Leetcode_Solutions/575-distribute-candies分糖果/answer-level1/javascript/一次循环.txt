### 解题思路
思路其实很简单，用map存储已经访问过的糖果种类，如果再每一种类拿一个的情况下`count == n`那么最大种类就就是res
如果每一种类拿一个的情况下无法满足`count == n`，那么也没必要回头重复选取满足平均了，因为重复选取种类并不会累加
那最终答案还是res

### 代码

```javascript
var distributeCandies = function(candies) {
    let res = 0, count = 0, n = candies.length / 2, i = 0;
    let visit = new Map();

    while (count < n && i < candies.length) {
        let cur = candies[i++];

        if (visit.has(cur)) {
            continue;
        } else {
            res++;
        }
        count++;
        visit.set(cur, true);
    }
    return res;
};
```