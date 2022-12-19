**脑一残，没看见是非负整数，瞎搞半天**
```javascript
/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function(n) {
    var num = 1
    for(i = 0 ;i<= n ;i++){
        num = (i*(i+1))/2;
        if(num > n){
            return i-1
        }else if(num === n){
            return i
        }
    }
};
```
