### 解题思路
从头截从尾截取找到所有相同字符串，然后入栈最后栈顶就是最长的

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var longestPrefix = function(s) {
    let result = "";
    let maxStack = [];

    for(let i = 0 ; i < s.length;i++){
        result = s.substr(0,i);

        if(result === s.substr(s.length- i )){
            maxStack.push(result);
        }
    }
    return maxStack.pop() || "";
};
```