### 解题思路
双指针从后向前遍历A的值和B的值，选取A或者B中最大值放到A的最后。

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
    var len = A.length-1;
    //将A从后向前遍历，选取A或者B中最大的值，放进来
    //A和B都不为空时
    while(m && n){
        A[len--] = A[m-1] > B[n-1] ? A[--m] : B[--n];
    }
    //如果A不为空，剩余A填充到A
    while(m) A[len--] = A[--m];
    //如果B不为空，剩余B填充到A
    while(n) A[len--] = B[--n];
};
```