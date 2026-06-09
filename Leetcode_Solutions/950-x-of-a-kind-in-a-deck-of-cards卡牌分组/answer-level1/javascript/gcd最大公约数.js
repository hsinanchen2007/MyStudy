```
var hasGroupsSizeX = function(deck) {
    if(deck.length<2){
        return false;
    }
    var map = new Map();
    for(var i=0;i<deck.length;i++){
        if(map.has(deck[i])){
            map.set(deck[i], map.get(deck[i])+1)
        }else{
            map.set(deck[i],1)
        }
    }
    var arr = [...map.values()]
    var res = arr[0]
    return arr.every(item =>(res = gcd(res,item))>1)
};
var gcd= (a,b)=>(b===0?a:gcd(b,a%b));
```
