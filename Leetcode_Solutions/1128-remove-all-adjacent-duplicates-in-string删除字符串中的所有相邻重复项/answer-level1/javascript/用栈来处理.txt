### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var removeDuplicates = function(S) {
    const source = [...S];
    const stack = [];
    while(source.length){
        const element = source.shift();
        if(stack[stack.length-1]==element)stack.pop();
        else stack.push(element);
    }
    return stack.join('');
};
```