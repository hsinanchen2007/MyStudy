虽然只是道简单的题，我太曲折了。。。
2.  纯递归会超时
2. 对1e9+7取余时忘了加括号！！！
3. 迭代时必须使用第三个变量保存结果（只用两个变量会发生与预期外的覆盖）
4. 不能只在return时对结果取余`return res%1e9+7`，这样的结果是错的；必须边迭代边取余，迭代过程中就有可能发生数值溢出的问题
5. 使用迭代+备忘录的时候，我曾经从i=0的下标触发，内部使用这样的判断if(!fibo[i]){...}，本来想要验证存在性，结果fibo[0](===0)也通过了验证，被误赋值为NaN

最后在这里重写一遍代码
```javascript
//1.1 循环迭代 保留中间状态
//空间复杂度O(n) 时间复杂度O(n)
function fib(n){
    let memo=[0,1];
    for(let i=2;i<=n;i++){
        memo[i]=(memo[i-1]+memo[i-2])%(1e9+7);
    }
    return memo[n];
}

//1.2 循环迭代 不保留中间状态
//空间复杂度O(1) 时间复杂度O(n)
function fib(n){
    if(n===0||n===1)return n;
    var num1=0,num2=1,res;
    for(let i=2;i<=n;i++){
        res=(num1+num2)%(1e9+7);
        num1=num2;
        num2=res;
    }
    return res;
}

//2.0 递归
//空间复杂度O(n) 时间复杂度O(n)
//我感觉递归的方法时间复杂度要优于1.1和1.2 
//因为不需要每次都迭代 假设我先计算了fib(9) 再调用fib(10)的时间复杂度就变成O(1)了
function fib(n){
    //备忘录
    let memo=[0,1];

    //如何避免每次都需要循环 从顶至下
    var fibo=function(n){
        if(n<2)return memo[n];
        memo[n]=typeof memo[n] ==='number'?memo[n]:(fibo(n-1)+fibo(n-2))%(1e9+7);
        return memo[n];
    }
   return fibo(n);
}

```