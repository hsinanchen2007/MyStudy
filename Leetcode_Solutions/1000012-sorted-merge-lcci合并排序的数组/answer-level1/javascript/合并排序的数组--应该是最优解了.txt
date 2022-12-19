### 执行结果
执行用时 : **60  ms**, 在所有 JavaScript 提交中击败了 93.25% 的用户
内存消耗 : **33.8 MB**, 在所有 JavaScript 提交中击败了 100.00% 的用户

### 解题思路
将两个数组从后往前进行比较，将较大的值放在 A 数组的末尾。
当 A 数组自有值没有值后，在 totalIndex 处，一次将 B 数组中的剩余值插入 A 数组。
aindex 不需要进行第二次 while 判断，因为这种情况说明所有 B 数组中的数据已经插入 A 数组，而 A 数组的自由值占据着 A 数组的头部， 数组已经排号序了。


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
    let totalIndex = A.length - 1;
    let aindex = m - 1;
    let bindex = n -1;    

    while( aindex >= 0 && bindex >= 0) {
        if ( A[aindex] < B[bindex] ) {
            A[totalIndex] = B[bindex];
            bindex--;
        } else {
            A[totalIndex] = A [aindex];
            aindex--;
        }
        totalIndex--;
    }

    while(bindex >= 0) {
        A[totalIndex] = B[bindex]
        bindex--;
        totalIndex--;
    }
};
```