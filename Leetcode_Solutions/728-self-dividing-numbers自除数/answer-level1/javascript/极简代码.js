### 代码

```javascript
var selfDividingNumbers = function(left, right) {
    let res = [];

    while (left <= right) {
        if (valid(left)) {
            res.push(left);
        }
        left++;
    }
    return res;
};

function valid(num) {
    let r = num;

    while (num) {
        let p = num % 10;
        
        if (p == 0 || r % p != 0) {
            return false;
        }
        num = Math.floor(num / 10);
    }
    return true;
}
```