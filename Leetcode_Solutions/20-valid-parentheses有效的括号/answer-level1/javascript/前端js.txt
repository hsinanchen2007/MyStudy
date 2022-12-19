### 解题思路
此处撰写解题思路
遍历整个字符串，当字符串等于'{','(','['的时候，将其压入到栈中，然后再出栈，判断是否匹配
### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    if (s === '' || s.length < 1) {
        return true;
    }
    var arr = s.split('');
    // [1,2,3,4]
    var stack = [];
    var ans = true;
    for (var i = 0; i < arr.length; i++) {
        if (arr[i] === '{' || arr[i]==='[' || arr[i]==='(') {
            stack.unshift(arr[i])
        }else {
            if(stack[0]==='{' && s[i]==='}') stack.shift();
            else if(stack[0]==='[' && s[i]===']') stack.shift();
            else if(stack[0]==='(' && s[i]===')') stack.shift();
            else ans = false;
        }
    }
    return stack.length === 0 && ans
};

```