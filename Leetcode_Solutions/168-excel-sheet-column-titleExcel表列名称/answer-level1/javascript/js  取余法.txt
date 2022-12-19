```
var convertToTitle = function(n) {
    //10进制转26进制,取余法
    let res="";
    while(n>0){
        let temp = n%26;
        n = Math.floor(n/26);
        if(temp==0){
            temp=26;
            n--;
        }
        res = String.fromCharCode(temp+64)+res;
    }
    return  res; 
};
```
