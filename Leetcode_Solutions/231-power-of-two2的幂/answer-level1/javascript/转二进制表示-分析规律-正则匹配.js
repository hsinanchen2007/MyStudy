### 解题思路
此处撰写解题思路
        
执行用时 :64 ms
, 在所有 javascript 提交中击败了99.82%的用户
内存消耗 :35.4 MB
, 在所有 javascript 提交中击败了44.55%的用户
```
 console.dir([1, 2, 4, 8, 16, 32, 64, 128].map(item => (item.toString(2))));
        /*
        "1"
        "10"
        "100"
        "1000"
        "10000"
        "100000"
        "1000000"
        "10000000"
        */

```
以1开头后面全是0： /^1{1}0*$/ 
### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    return /^1{1}0*$/.test(n.toString(2))
};
```