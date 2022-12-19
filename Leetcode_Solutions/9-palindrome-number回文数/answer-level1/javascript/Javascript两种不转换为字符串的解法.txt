第一种，反转整数,再判断反转后的整数是否和输入的整数相等：

```
function f1(x) {
    let num = 0;
    const f = function(x) {
        if ( Math.ceil(x  / 10 ) !== 0 || -10 < x  && x < 0 ){    //  -10 < x < 0 是考虑到负数的情况
            let temp1 = x % 10;
            let temp2 = (x - temp1) / 10;
            num = num * 10 + temp1;
            f(temp2)
        }
        if(num > 2147483647 || num < -2147483648) {
            return 0;
        }
        return num === x;
    };
    return f(x)
};
```
第二种，先计算出整数的位数，再取每一位上的值，再判断对应位数的值是否相等。
```
function f(x) {
    let tmp = x;
    let capacity = 1;
    while (tmp / 10 >= 1 || tmp / 10 <= -1) {
        tmp = tmp / 10;
        capacity = capacity + 1;
    }
    let tmpArr = [];
    for (let i = 0; i < capacity; i++) {
        if(x > 0) {
            tmpArr.push(Math.floor(x / Math.pow(10, i)) % 10)
        } else if(x < 0){
            tmpArr.push(Math.ceil(x / Math.pow(10, i)) % 10)
        } else {
            return true;
        }
    }
    for(let i = 0; i <= capacity / 2 - 1; i ++ ) {     // 也可以 i < capacity / 2，这样的话capacity为单数时多算一次，对结果无影响。
        if(tmpArr[i] !== tmpArr[capacity - i - 1]) {
            return false
        }
    }
    return true;
}
```