var cuttingRope = function(n) {
   if(n === 2) return 1
   if(n === 3 ) return 2
   if(n === 4) return 4
   let sum = 1;
   while(n> 4) {
       sum*=3
       n-=3
   }
   return sum*n
};