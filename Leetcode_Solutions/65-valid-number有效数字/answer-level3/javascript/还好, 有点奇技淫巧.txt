```
/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {

    try{
        let = num = parseFloat(s);
        
        if(isNaN(num) === true){
            return false;
        }

        if(num == s){
            return true;
        }else{
            return false;
        }
        
    }catch(err){
        return false;
    }
};
```
