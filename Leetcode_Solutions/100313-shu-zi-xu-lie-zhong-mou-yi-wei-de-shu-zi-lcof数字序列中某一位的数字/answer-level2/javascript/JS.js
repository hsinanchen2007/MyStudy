### 代码

```javascript
var findNthDigit = function(n) {
    n -= 1;
    for(let i = 1; i < 11; i++){
        let j = Math.pow(10, i -1);
        if(n < 9 * j * i){
            return String((j + n / i))[n % i]
        }
        n -= 9 * j * i;
    }
    return 0
};


```