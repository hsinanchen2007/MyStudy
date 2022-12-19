function gcd(a, b) {
  return a % b === 0 ? b : gcd(b, a % b);
}

var hasGroupsSizeX = function(deck) {
    let len = deck.length;
    if(len <= 1 || len> 10000) return false;
   
    
    const map = {};
    
    for(let item of deck){
        if(!map[item]){
            map[item]=[]
        }
        map[item].push(item)
    }
    
    
    let arr = [];
    
    for(let item in map){
        arr.push(map[item].length)
    }
    
    while (arr.length > 1) {
        arr.push(gcd(arr.pop(), arr.pop()))
    }
    
    return (arr[0] > 1)
    
};

