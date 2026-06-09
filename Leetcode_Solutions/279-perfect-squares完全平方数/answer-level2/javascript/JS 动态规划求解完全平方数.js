### 解题思路

一开始想了很半天，但是真正运行起来之后就简单了

使用的动态规划方法，动态规划的精髓就是将一个复杂问题分解成简单问题逐个击破

外层循环代表的是当前第几步相乘，内存循环则是当前这一步的所有可能。内层中判断，核心在与内层循环的这一则运算： `rest = num - i * i`，num 是上层循环中未解决的问题，即 上一层的 rest。如果当前 rest（剩余未解决的问题）小于0，则代表 i 循环的过大，break；如果等于0，则其只可能是通过最少次循环得到的数字，则其为我们要找的值。如果大于0，则证明当前解不足够完成这个问题，则将他的rest（剩余问题）放入队列中，等待下次外层循环后处理。

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {
    let queue = []
    let indexs = new Set()
    queue.push([n, 0])
    indexs.add(n)

    while(queue.length) {
        let [num, step] = queue.shift()
        for(let i = 0;;i++) {
            let rest = num - i * i
            if (rest < 0) break
            if (rest === 0) return step + 1
            if (!indexs.has(rest)) {
                queue.push([rest, step + 1])
                indexs.add(rest)
            }
        }
    }
    
};
```