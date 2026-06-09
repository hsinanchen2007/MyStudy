### 解题思路
看一篇文章得到的思路
虽然通过了 但是时间消耗很长 达到6s 但是比暴力法快多了 因为暴力法在字符串长的时候 直接超出时间限制 
下一步准备用 第三种办法【ps.从别人那里得到的启发 公众号：苦逼的码农】嘻嘻

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    // 栈存储
    // 时间复杂度 O(n)
    let stack = [-1];
    let max = 0;
    for( const i in s ){
        if( s[i] === '(' ){
            stack.push(i); // 就是要放索引值 不是字符本身
        }else if(s[i] === ')'){
            console.log(stack);
            if( stack.length <= 0 ){
                stack.push(i); // 相当于刚开始的 -1 初始化： 此时的 i 对应的 ')' 已经匹配不到 '(' 属于无效状态 i + 1 往后的有可能是有效状态 万一还是')' 同样无效 需要出栈 判断栈为空 设置初始值后 那么直接走循环 因为还是无效的不用走 相减的那一步 不知道我说的明白么^_^ -1 就是 0 的前一个索引而已
            }else{
                stack.pop();
                if( stack.length <= 0 ){
                    stack.push(i);
                    continue;
                }
                max = max > i - stack[stack.length - 1] ? max : i - stack[stack.length - 1];
                console.log(max);
            }
        }
    }
    return max;
};
```