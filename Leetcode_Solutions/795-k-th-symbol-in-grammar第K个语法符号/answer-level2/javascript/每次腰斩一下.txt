### 解题思路
![image.png](https://pic.leetcode-cn.com/a8b6cd0e7ad9be571254da3fb4595869380b18952aea49a3ca2ff563cf9a29b2-image.png)

一开始习惯性地开了个dp[]来动态，发现会javascript heap out of memory, 想了下才醒悟，只需要取“上一行的K一半那个即可”。
### 代码

```javascript
/**
 * @param {number} N
 * @param {number} K
 * @return {number}
 */
var kthGrammar = function (N, K) {
    if (N === 1) return "0";
    if (N === 2) return "01".substr(K - 1, 1);

    if (K % 2 === 0) {
        return kthGrammar(N - 1, K / 2) === "0" ? "1" : "0";
    } else {
        return kthGrammar(N - 1, (K + 1) / 2) === "0" ? "0" : "1";
    }
};
```