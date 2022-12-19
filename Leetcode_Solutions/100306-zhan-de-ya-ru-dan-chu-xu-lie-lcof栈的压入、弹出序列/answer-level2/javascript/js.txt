### 解题思路
辅助栈
当两个 pushed 数组或者poped数组的长度大于0的时候
stack最后一项跟popped首项相等的话 都推出去

### 代码

```javascript
/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */
var validateStackSequences = function(pushed, popped) {
    let stack = []
    while(pushed.length > 0 || popped.length > 0) {
        if (stack[stack.length - 1] == popped[0]) {
            stack.pop()
            popped.shift()
        } else if (pushed.length > 0) {
            stack.push(pushed.shift())
        } else {
            return false
        }
    }
    return true
};
```