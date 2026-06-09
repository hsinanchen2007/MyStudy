### 解题思路

两种方法求解
递归
利用数组，将每次n的值保存到数组中
通过数组的index正好能取到对应的值

动态规划
Arr[n] 就是每个位置的和
F(n) =F(n-1) + F(n-2) 动态转移方程
### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 * 递归保存法
 * 还是递归的思想，利用数组，将每次n的值保存到数组中
 * 通过数组的index正好能取到对应的值
 */

let arr = [0,1];
var fib = function(n) {
    if(n ==0 || n ==1){return n}
     if(arr[n]){
        return arr[n]
    }
    arr[n] = (fib(n-1) + fib(n-2))%1000000007
    return arr[n]
};

var fib = function(n) {
    let arr = [0,1]
    for(let i= 2; i< n; i++){
        arr[i] = arr[i -1] + arr [i-2]
    }   
    return arr[n]%1000000007
};

```