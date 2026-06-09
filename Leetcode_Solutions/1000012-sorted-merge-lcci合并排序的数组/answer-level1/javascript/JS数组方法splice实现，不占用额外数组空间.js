![image.png](https://pic.leetcode-cn.com/f5fefe27bce298f55470b38b702463412e37e6b22254882587155215237cb723-image.png)
```
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function(A, m, B, n) {
    let i=0,j=0;
    A.splice(m,n);
    while(i<m&&j<n){
        if(B[j] < A[i+j]){
            A.splice(i+j,0,B[j]);
            j++;
        }else{
            i++;
        }
    }
    while(j<n){
        A.splice(i+j,0,B[j]);
        j++;
    }
};
```

