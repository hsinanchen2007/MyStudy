### 代码

```javascript
/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */
var validateStackSequences = function(pushed, popped) {
    var stack = [];
    var len = pushed.length;
    for(var i = 0; i < len; i++){
        stack.push(pushed.shift());
        while(stack.length != 0 && stack[stack.length-1] == popped[0]){
            stack.pop();
            popped.shift();
        }
    }
    return stack.length == 0;
};
```