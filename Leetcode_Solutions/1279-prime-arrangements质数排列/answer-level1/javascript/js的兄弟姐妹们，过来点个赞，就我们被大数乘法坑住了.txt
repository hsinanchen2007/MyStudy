这题不难，但是对没有bigint的js有个不小的坑： 
此题若是直接求出了： 
1. 素数的全排列方式总数对于`10**9+7`的余数`a`
2. 非素数的全排列方式总数对于`10**9+7`的余数`b`
若直接计算 `(a*b)%(10**9+7)`时由于数位溢出，导致计算结果不准确，此不准确结果为：`682289019`
因此最终的`a*b`乘法应该将其中的一个数拆为两部分，分别相乘并取余：

js大数相乘并取余

```javascript
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

最终代码为： 

```javascript
var numPrimeArrangements = function(n) {
    let MOD = 10**9 + 7;
    function A(n,m){
        return (m===0?1:A(n,m-1)*(n-m+1)) % MOD;
    }
    
    function su(a){
        if(a<2)return false;
        if(a===2)return true;
        for(let i=2;i<a;i++){
            if(a%i===0)return false;
        }
        return true;
    }
    
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
    
    let numSu = 0;
    for(let i=1;i<=n;i++){
        if(su(i)){
            numSu++;
        }
    }
 
    let a = A(numSu,numSu);
    let b = A(n-numSu,n-numSu);
 
    return (a*b) % MOD;
};
```