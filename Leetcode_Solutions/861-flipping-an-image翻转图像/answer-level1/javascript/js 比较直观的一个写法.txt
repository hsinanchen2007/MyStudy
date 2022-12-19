执行用时 :76 ms, 在所有 JavaScript 提交中击败了95.54%的用户
内存消耗 :35.3 MB, 在所有 JavaScript 提交中击败了29.55%的用户

比较直观的一个写法，采用亦或进行交换，采用按位非进行0与1的互换

```
var flipAndInvertImage = function(A) {
    
    for(let i=0;i<A.length;i++){
        for(let j=0;j<Math.floor(A[i].length/2 + A[i].length % 2);j++){
            
            let left = j;
            let right = A[i].length-1-j;
            
            if(left != right){
                A[i][left] ^= A[i][right];
                A[i][right] ^= A[i][left];
                A[i][left] ^= A[i][right];
                
                A[i][left] = ~A[i][left] + 2;
                A[i][right] = ~A[i][right] + 2;
                
            }else{
                A[i][j] = ~A[i][j] + 2; 
            }
            
        }
    }
    
    return A;
    
};
```
