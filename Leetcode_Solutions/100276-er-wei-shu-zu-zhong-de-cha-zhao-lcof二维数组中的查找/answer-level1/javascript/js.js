```
var findNumberIn2DArray = function(matrix, target) {
   for(let i=0;i<matrix.length;){
     if(matrix[i][0]>target){
       i++
     }else{
       if(matrix[i].includes(target)){
         return true
       }else{
         i++
       }
     }
   }
   return false 
};
```
