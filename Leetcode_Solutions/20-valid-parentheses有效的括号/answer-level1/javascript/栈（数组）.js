### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var str = s.split(''),
        obj = {'{':'}','[':']','(':')'},
        stack = []
    for(var i=0;i<str.length;i++){
        v=str[i]
        if(v=='{'||v=='['||v=='(')
            stack.push(v)
        else{
            if(obj[stack[stack.length-1]]==v)
                stack.pop()
            else
                return false
        }
    }
    return !stack.length
};
```

//笨方法