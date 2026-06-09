### 解题思路
逆序双指针

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
    let p = m + n - 1, cur = 0
    --m;
    --n;
    while(m >=0 || n >= 0){
        if( m < 0){
            cur = B[n]
            n--
        }else if(n < 0){
            cur = A[m]
            m--
        }else if(A[m] < B[n]){
            cur = B[n]
            n--
        }else{
            cur = A[m]
            m--
        }
        A[p] = cur
        p--
    }
};
```