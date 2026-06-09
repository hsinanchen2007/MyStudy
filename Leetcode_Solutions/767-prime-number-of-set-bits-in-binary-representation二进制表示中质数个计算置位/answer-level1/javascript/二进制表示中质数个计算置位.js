```js
var countPrimeSetBits = function(L, R) {
    // 存储二进制中1的个数
    let arr = []
    for (let i = L; i <= R; i++) {
        arr.push(i.toString(2).replace(/0/g, '').length)
    }
    // 判断一个数是否为质数
    let isPrime = function(num) {
        if (num === 1) {
            return false;
        }
        for (let i = 2; i < num; i++) {
            if (num % i === 0) {
                return false;
            }
        }
        return true
    }
    //质数个数
    let count = 0;
    for (let item of arr) {
        if (isPrime(item)) {
            count++
        }
    }
    return count
};
```