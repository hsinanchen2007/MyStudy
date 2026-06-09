```
var superPow = function(a, b) {

    var jiangmi = function(base, power){
        var result = 1;
        while(power > 0){
            if (power % 2 === 1) {
                result = result * base % 1337;
            }
            power = parseInt(power / 2);
            base = (base * base) % 1337;
        }
        return result;
    }
    
    var result = 1;
    var _length  = b.length;
    a = a % 1337;
    for(var i = _length - 1; i >=0; i--){
        var tempPower = b[i];
        result = result * jiangmi(a, tempPower) % 1337;
        a = jiangmi(a, 10) % 1337;
    }
    
    return result % 1337;
};
```
