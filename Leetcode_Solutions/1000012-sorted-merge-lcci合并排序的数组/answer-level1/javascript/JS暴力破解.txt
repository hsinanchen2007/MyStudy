```
/**
 * @param {number[]} A
 * @param {number} m
 * @param {number[]} B
 * @param {number} n
 * @return {void} Do not return anything, modify A in-place instead.
 */
var merge = function(A, m, B, n) {
    if(m == 0 && n == 0){
        return null;
    }
    if(m == 0 && n != 0){
        B.forEach((el,index)=>{
            A[index] = el;
        })
        return A;
    }
    if(m != 0 && n == 0){
        return A;
    }
   for(let i=0;i<n;i++){
       A[i+m] = B[i];
   }
    A.sort((a,b)=>a-b);
    console.log(A);
    return A;
};
```
