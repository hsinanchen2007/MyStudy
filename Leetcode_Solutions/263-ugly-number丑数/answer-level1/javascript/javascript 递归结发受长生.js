```
 */
var isUgly = function(num) {
    let ar = [2,3,5]
    let a = false;
    num = Number(num);
    if(num===1) return true;
    if(num>Math.pow(2,31)-1||num<1) return false
	getNum(0,num);
    function getNum(n,num){
       if(num%ar[n]===0){
           if(num/ar[n]===1){
                 a = true
				
           }else{
               getNum(n,num/ar[n])
			
           }
          
       }else{
           if(n<2){
               getNum(n+1,num)
			
           }else{
                a = false
			
           }
           
       }
	   return
   }

    return a
};
```
