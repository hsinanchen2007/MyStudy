### 解题思路
先去重了一下,结果是我自作多情 ——_——
### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    return arr.sort((a,b)=>a-b).slice(0,k)
};
```