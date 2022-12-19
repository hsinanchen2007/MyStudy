*法一*

```js
var isUgly = function(num) {
    while(num > 1) {
        if (Number.isInteger(num/2)) {
            num /= 2;
        } else if (Number.isInteger(num/3)) {
            num /= 3
        } else if (Number.isInteger(num/5)) {
            num /= 5
        } else {
            return false
        }
    }
    return num === 1
};

var num = 6;
console.log(isUgly(num));
```

*法二：同法一*

```js
var isUgly2 = function(num) {
    if (num < 1) {
        return false
    }
    while (num % 2 === 0) {
        num /= 2;
    } 
    while (num % 3 === 0) {
        num /= 3
    } 
    while (num % 5 === 0) {
        num /= 5
    }
    return num === 1
};
```

