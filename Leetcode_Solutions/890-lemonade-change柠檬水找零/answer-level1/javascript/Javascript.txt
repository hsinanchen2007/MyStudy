```javascript
var lemonadeChange = function (bills) {
    var five = 0;
    var ten = 0;
    for (let i = 0; i < bills.length; i++) {
        if (bills[i] === 5) {
            five++
        }
        if (bills[i] === 10) {
            ten++;
            five--;
            if (five < 0) {
                return false;
            }
        }
        if (bills[i] === 20) {
            if (ten > 0) {
                ten--;
                five--;
            } else {
                five -= 3;
            }
            if (five < 0 || ten < 0) {
                return false;
            }
        }
    }
    return true;
};
```