```
var isValid = function(s) {
   if(s.length%2!==0) return false
    let obj= {
        '(':-1,
        ')':1,
        '{':-2,
        '}':2 ,
        '[':-3 ,
        ']':3  
        }
        let arr =['']
   for( var i=0;i<s.length;i++){
       const a = obj[arr[arr.length-1]]+obj[s[i]]
       if(a==0){
           arr.pop()
       }else{
           arr.push(s[i])
       }
   }
   if(arr.length==1&&arr[0]==''){
       return true
   }
  return false
};
```
