### 解题思路
![image.png](https://pic.leetcode-cn.com/bd6658a24508aab2523f4f9839073dce8a29990c03a41b291e3337030928b0e8-image.png)

用一个map放每一个数字的前一位和后一位，用一个set放已遍历的四位数，好像并没有快多少-_-!!

### 代码

```javascript
/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */
var openLock = function(deadends, target) {
    if (target === "0000") return 0;
    if (deadends.includes("0000")) return -1;

    let step = 0,
        que = [],
        init = [0, 0, 0, 0],
        m = new Map(),
        rec = new Set();

    m.set(0, [1, 9]);
    m.set(1, [2, 0]);
    m.set(2, [3, 1]);
    m.set(3, [4, 2]);
    m.set(4, [5, 3]);
    m.set(5, [6, 4]);
    m.set(6, [7, 5]);
    m.set(7, [8, 6]);
    m.set(8, [9, 7]);
    m.set(9, [0, 8]);

    que.push(init);
    rec.add("0000");

    while (que.length) {
        let len = que.length;
        step++;
        for (let i = 0; i < len; i++) {
            let curr = que.shift();
            for (let j = 0; j < 4; j++) {
                let inc = curr.slice(0);
                const cj = curr[j];
                inc[j] = m.get(cj)[0];
                if (rec.has(inc.join(""))) {
                    continue;
                } else {
                    rec.add(inc.join(""));
                }
                if (inc.join("") === target) {
                    return step;
                } else if (!deadends.includes(inc.join(""))) {
                    que.push(inc);
                }
            }
            for (let j = 0; j < 4; j++) {
                let des = curr.slice(0);
                const cj = curr[j];
                des[j] = m.get(cj)[1];
                if (rec.has(des.join(""))) {
                    continue;
                } else {
                    rec.add(des.join(""));
                }
                if (des.join("") === target) {
                    return step;
                } else if (!deadends.includes(des.join(""))) {
                    que.push(des);
                }
            }
        }
    }
    return -1;
};
```