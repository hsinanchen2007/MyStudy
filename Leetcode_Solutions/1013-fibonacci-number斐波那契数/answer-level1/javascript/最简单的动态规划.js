### 解题思路
以fib(0)、fib(1)、fib(2)、...、fib(N)的顺序计算
fib(N)=fib(N-1)+fib(N-2)

### 代码

```javascript
/**
 * @param {number} N
 * @return {number}
 */
var fib = function(N) {
    if(N<1) return N
    let prev=0,curr=1
    for(let i=1; i<N;i++){
        let tmp = prev
        prev = curr
        curr = tmp + curr
    }
    return curr
};
```