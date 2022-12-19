## 思路

### 思路1

第一种错误思路，开括号('{','(','[')和闭括号('}',')',']')分别用两个堆栈去存储，然后再每个弹出来对比是不是一对。但是这样只是对((([[{}])))，()[]{},左右括号刚好分离的，如果是[{}()]这样的就识别不了,所以我们不能先把开括号和闭括号分别分离后再对比，而且两个堆栈空间消耗大，那么能不能用一个堆栈就解决。

### 思路2

然后就想到遍历字符串的时候，如果是开括号的话就推入栈，然后如果是闭括号的话，就把开括号栈的栈顶的字符推出来，看和闭括号是不是一对，怎么判断是不是一对，我们可以定一个map对象:

```js
let map = {
	'{': '}',
	'[': ']',
	'(': ')'
}
```

然后如果不是一对的话就返回false，如果是的话就继续遍历，直到遍历完了，如果开括号栈的长大于0，那么就返回false（因为开括号的数量大于闭括号的数量），否则返回true.

那么我们还要考虑到一个问题就是一开始就是闭括号，那么我们肯定返回false

还有如果是空串的话，我是直接返回的true。

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let map = {
        '{': '}',
        '[': ']',
        '(': ')'
    }
    if (s === '') {
        return true;
    } else {
        let stack1 = [];
        if (s[0] === '}' || s[0] === ']' || s[0] === ')') return false
        if (s.length % 2 !== 0 ) return false
        for (var i in s) {
            if (s[i] !== '}' && s[i] !== ']' && s[i] !== ')' ) {
                stack1.push(s[i]);
            } else {
                if(map[stack1.pop()] !== s[i] ) {
                    return false
                }
            }
        }
        return !stack1.length
    }
};
```


但是一看感觉代码太多了，能不能再优化一下，把特殊情况不要单独放出来。

### 优化

第一个优化，空字符串的情况

我们其实不用判断是不是空串，因为他不会走for遍历，然后stack1.length就是0，所以会返回true.

第二个优化就是第一个字符是闭括号或则是闭括号和开括号数量不等情况其实都能在for循环里解决，因为遍历到闭括号时会去比对开括号栈，如果第一个就是闭括号的话，那么开括号栈推出的应该是undefined，肯定不等于闭括号，所以会返回false。

第三个优化，我判断一个字符是不是开括号是通过`if(s[i] !== '}' && s[i] !== ']' && s[i] !== ')')`去实现，其实可以写为`if (s[i] in map)`

```js
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let map = {
        '{': '}',
        '[': ']',
        '(': ')'
    }
    let stack1 = [];
    for (var i in s) {
        if (s[i] in map) {
            stack1.push(s[i]);
        } else {
            if(map[stack1.pop()] !== s[i] ) {
                return false
            }
        }
    }
    return !stack1.length
};
# ```