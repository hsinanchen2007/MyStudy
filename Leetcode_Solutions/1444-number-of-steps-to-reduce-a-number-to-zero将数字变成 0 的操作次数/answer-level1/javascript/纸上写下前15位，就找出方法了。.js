### 解题思路
如题，一开始以为可以归一化成公式解法，没找到规律，在纸上写下前12个输入返回答案，就有了简单的算法，牺牲一定空间，换取时间上的计算优势。
| Input  | Output  |
|---|---|
|  0 | 0  |
|  1 | 1  |
|  2 | 2  |
|  3 | 3 |
|  4 | 3 |
|  5 | 4  |
| 6 | 4|
|7|5|
|8|4|
|9|5|
|10|5|
|11|6|
|12|5|
......

从3开始都可以复用到之前计算的答案，所以就有了下面的递归方案。



### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps = function (num) {
    var temp = { 0: 0, 1: 1, 2: 2 };

    function travese(n) {
        if (temp[n] !== undefined) {
            return temp[n];
        }
        if(n % 2 === 0) {
            return travese(parseInt(n/2)) + 1
        } else {
            return travese(n - 1) + 1
        }
    }

    return travese(num);

};
```