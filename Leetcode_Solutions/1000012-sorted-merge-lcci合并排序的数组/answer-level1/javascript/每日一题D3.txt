### 解题思路
用**双指针**的思想

- 当`m`与`n`都不为零时，由于A数组已经预留好了空间，所以考虑**从后往前**比较两个数组的值，将值较大的填入A数组后部。若从前往后比较，必定会覆盖A数组原元素，很不方便

- 当`m = 0`跳出循环时，依次填入B数组剩下的排序内容即可

- 当`n = 0`跳出循环时，无需再去动A数组，它本身就是已经排好序的了

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
    let len = A.length - 1;
    while(m && n){
        if(A[m - 1] > B[n - 1]){
            A[len] = A[m - 1];
            m--;
        }else{
            A[len] = B[n - 1];
            n--;
        }
        len--;
    }
    while(n){
        A[len] = B[n - 1];
        n--;
        len--;
    }
};
```
