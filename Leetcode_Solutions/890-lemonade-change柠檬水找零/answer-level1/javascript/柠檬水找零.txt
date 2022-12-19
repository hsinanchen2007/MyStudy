思路：

- 当收到5时
    + 店家手里的5++

- 当收到10时
    + 优先匹配一张5如有返回true
        - 店家手里的5--，10++
        - 如没有返回false

- 当收到20时
    + 优先匹配店家手里的一张10和一张5，如有返回true
        - 店家手里的10--
        - 店家手里的5--
    + 如没有重新匹配3张5，如有返回true
        - 店家手里的5-=3
    + 如都没有返回false



```js
var lemonadeChange = function(bills) {
    let count5 = 0;
    let count10 = 0;
    for (let i = 0; i < bills.length; i++) {
        if (bills[i] === 5) {
            count5++
        } else if (bills[i] === 10) {
            if (count5 > 0) {
                count5--;
            } else {
                return false
            }
            count10++;
        } else {
            if (count10 > 0) {
                count10--
                count5--
            } else {
                count5 -= 3
            }
        }
        if (count5 < 0) {
            return false
        }
    }
    return true;
};
```

