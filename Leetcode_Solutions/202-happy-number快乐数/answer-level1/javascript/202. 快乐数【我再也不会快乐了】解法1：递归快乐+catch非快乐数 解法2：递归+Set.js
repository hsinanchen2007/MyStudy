
解法一：递归快乐+catch非快乐数

```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function (n) {
    if (n == 1) return true;

    try {
        function quadratic(num) {
            return Math.pow(parseInt(num), 2);
        }
        var nextNum = -999;
        if (`${n}`.length === 1) { 
            // 7 true, 2 false 
            nextNum = quadratic(n);
        } else {
            // 19 true, 78 false
            nextNum = `${n}`.split("").map(quadratic).reduce((acc, cur) => acc + cur);
        }
        while (nextNum !== 1) {
            // 递归
            nextNum = isHappy(nextNum);
            return nextNum;
        }
        return nextNum === 1;
    } catch (err) {
        // 一直循环的非快乐数会抛出异常
        return false;
    }

};
```

慢是慢了点，至少能跑，再想办法优化吧。

![image.png](https://pic.leetcode-cn.com/e34b64a3077d1db7b058561de2a1263253138afdd254f11f3e198310631f0f0b-image.png)


解法2：递归+Set

```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function (n, arr) {
    if (n == 1) return true;
    var nextNums = arr || [];
    var nextNumsSet = new Set(nextNums);
    // 通过Set对数组去重，比较size和length的大小
    if (nextNumsSet.size !== nextNums.length) {
        return false;
    }
    function quadratic(num) {
        return Math.pow(parseInt(num), 2);
    }
    var nextNum = -999;

    if (`${n}`.length === 1) {
        // 7 true, 2 false 
        nextNum = quadratic(n);
    } else {
        // 19 true, 78 false
        nextNum = `${n}`.split("").map(quadratic).reduce((acc, cur) => acc + cur);
    }
    while (nextNum !== 1) {
        nextNums.push(nextNum);
        // 递归
        nextNum = isHappy(nextNum, nextNums);
        return nextNum;
    }
    return nextNum === 1;
};
```

这才算是一种正常的解法。
![image.png](https://pic.leetcode-cn.com/d8ca57b0246720c7d2682c0216dc85202f894e17e4057c43020fa1a1375442ec-image.png)
