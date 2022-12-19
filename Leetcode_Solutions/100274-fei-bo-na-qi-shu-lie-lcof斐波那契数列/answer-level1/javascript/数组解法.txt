### 解题思路
1.递归超时
```
var fib = function(n) {
    if(n<=1){
      return n
    }else{
      return (fib(n-1) + fib(n-2))%1000000007
    }
};
```
2.数组解法，需要迭代n次，空间也需要开辟n个


### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
   //快速初始化
    const arr = new Array(n+1).fill(0)
    arr[1] = 1
    for(let i = 2,len=n; i<=len ; i++){
        arr[i] = (arr[i-1]+arr[i-2]) % 1000000007 ;
    }
    return arr[n]
};
```