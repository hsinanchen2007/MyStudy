### 解题思路
此处撰写解题思路

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
    var j = 0;
    var s = m + n;
     A.splice(m);
    if(B[n-1]<A[0]){
        A.unshift(...B)
    }else if(B[0]>A[m-1]){
         A.push(...B)
    }else {
        for (var i = 0;i<m;i++){
                if(B[j]<A[i] && j<n){
                    A.splice(i,0,B[j]);
                    j++;
                    m++;
                }
            }
            if(j<n){
            var arr = B.slice(j);
            A.push(...arr);
            }
    }
   
};
```