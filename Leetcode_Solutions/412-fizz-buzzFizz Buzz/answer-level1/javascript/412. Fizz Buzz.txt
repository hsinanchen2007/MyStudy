## 题目剖析

### 题目描述

写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3. 如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

### 思路分析

题目其实很简单，分别做判断就行了，所以第一版程序如下：

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function(n) {
    var result=[];
    for(var i=1;i<n+1;i++){
        if(i%3==0&&i%5==0){
            result.push('FizzBuzz');
        }
        else if(i%3==0){
            result.push('Fizz');
        }
        else if(i%5==0){
            result.push('Buzz');
        }
        else{
            result.push(i.toString());
        }
    }
    return result;
};
```

然而我们发现，这里其实存在可以优化的地方，因为 ``Fizz``和 ``Buzz`` 是可以拼接起来的，所以我们用变量来存即可。

## 示例代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function(n) {
    const result = []
    for(let i = 1; i < n + 1; i++){
        let ans = ''
        ans += i % 3 ? '' : 'Fizz'
        ans += i % 5 ? '' : 'Buzz'
        if (!ans) {
            ans += i
        }
        result.push(ans)
    }
    return result
};
```