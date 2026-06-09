```
var majorityElement = function(nums) {
   let count=0;
   let candidate=null;
   nums.forEach((item)=>{
     if(count===0){
       candidate=item
     }
     count+=candidate===item?1:-1
   }) 
   return candidate
};
```
