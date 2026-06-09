*法一：暴力递增判断*

```js
var isPerfectSquare = function(num) {
    var i = 1;
    while(i * i <= num) {
        if (i * i < num) {
            i++;
        } else if (i * i === num) {
            return true
        }
    }
    return false
};
```

*法二： 二分查找*

```js
var isPerfectSquare2 = function(num) {
    let left = 1;
    let right = num;
    while (left <= right) {
        let mid = parseInt((left+right)/2);
        let product = mid * mid;
        if (product === num) {
            return true;
        } else if (product > num) {
            right = mid - 1;
        } else {
            left = mid + 1
        }
    }
    return false;
};
```


