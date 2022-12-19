### 解题思路
数组保存，for循环代替递归

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
//法一，递归，超出时间

// var fib = function(n) {
//     var res;
//     if(n==0) return 0;
//     if(n==1) return 1;
//     if(n>=2){
//         res= (fib(n-1)+fib(n-2))%(1e9+7);
//     }
//     return res;

// };

//法二，for循环
var fib = function(n) {
    var fibon=[0,1];
    if(n>=2){
        for(let i=2;i<=n;i++){
            fibon[i]=(fibon[i-1]+fibon[i-2]) %(1e9+7);
        }
    }
    return fibon[n]
};

```