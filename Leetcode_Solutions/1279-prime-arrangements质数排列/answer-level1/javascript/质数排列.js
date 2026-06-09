
- 素数的全排列方式总数对于`10**9+7`的余数`a`
- 非素数的全排列方式总数对于`10**9+7`的余数`b`

若直接计算 `(a*b)%(10**9+7)`时由于数位溢出，导致计算结果不准确，此不准确结果为：682289019
因此最终的a*b乘法应该将其中的一个数拆为两部分，分别相乘并取余：

**js大数相乘并取余**

```js
let MOD = 10**9+7;
function multi(a,b){
    //将b拆成2部分
    let t=Math.floor(b/100000),
        t2=b % 100000
    let sum=0
    for(let i=0;i<t;i++){
      sum=(sum+100000*a) % MOD
    }
    sum=(sum+t2*a)%MOD
    return sum
}
```

**最终代码为：**

```js
var numPrimeArrangements = function(n) {
    const MOD = 10**9+7;
    // 小于等于n的质数有多少个
    // 厄拉多塞筛法
     var numPrime = function(n) {
        let arr = []
        let count = 0
        for (let i = 2; i <= n; i++) {
            if (!arr[i]) {
                count++
                for (let j = i * 2; j <= n; j = j + i) {
                    arr[j] = true
                }
            }
        }
        return count
    }
    // 排列组合
    var pailie = function(n) {
        let res = 1;
        while(n > 1) {
            // res *= n
            res = res * n % (10**9 + 7)
            n--
        }
        return res
    }
    // 质数个数
    let primeNum = numPrime(n)
    // 合数个数
    let composite = n - primeNum;

    let a = pailie(primeNum) 
    let b = pailie(composite)

    function multi(a,b){
        //将b拆成2部分
        let t = Math.floor(b / 100000),
            t2 = b % 100000
        let sum = 0
        for(let i = 0; i < t; i++){
          sum = (sum + 100000 * a) % MOD
        }
        sum = (sum + t2 * a) % MOD
        return sum
    }
    return multi(a,b)
};
```
