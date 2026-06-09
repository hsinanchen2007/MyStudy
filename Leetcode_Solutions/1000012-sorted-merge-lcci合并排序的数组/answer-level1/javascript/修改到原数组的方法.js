### 解题思路
只能在A数组上面改 所以方法限定在需要能修改到原数组的上

执行用时 :64 ms, 在所有 JavaScript 提交中击败了77.42%的用户；
内存消耗 :34.7 MB, 在所有 JavaScript 提交中击败了100.00%的用户
### 代码

```javascript
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function(A, m, B, n) {
    A.splice(m,A.length-m);
    for(var i = 0;i<n;i++){
        A.push(B[i]);
    }
    A.sort(function(a,b){return a-b});
};
```