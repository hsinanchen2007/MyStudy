### 解题思路
 倒序，从后向前进行遍历

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
    var i = A.length - 1;
    while(m > 0 && n > 0)
    {
        if(A[m-1] > B[n-1])
        {
            A[i] = A[m-1];
            m--;
        }

        else
        {
            A[i] = B[n-1];
            n--;
        }
        i--;
    }

    while(n--)
    {
        A[i] = B[n];
        i--;
        
    }

    return A;
};
```