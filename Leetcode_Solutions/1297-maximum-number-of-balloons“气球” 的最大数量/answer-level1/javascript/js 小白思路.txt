1. 
```
     * @param {string} text
 * @return {number}
 */
var maxNumberOfBalloons = function(text) {
    let obj = {}
    let reg = /[balon]/i
    
    let num1 = 0
    let num = text.length
    
    
    for (let i = 0; i < text.length; i++) {
        if (obj[text[i]] === undefined && reg.test(text[i]) ) {
            obj[text[i]] = 1
        } else if (obj[text[i]]) {
            obj[text[i]] += 1
        }
    }
    
    if (!obj.b || !obj.a || !obj.l || !obj.o || !obj.n) {
        return 0
    }

    for (var key in obj) {
        if (key === 'l' || key === 'o') {
            num1 = Math.floor(obj[key] / 2)
        } else {
            num1 = obj[key]
        }
        
        num = Math.min(num, num1)
    }
    
    return num
};
```
2. 
