```
var isValid = function (s) {
    let map = new Map();
    map.set(')', '(');
    map.set(']', '[');
    map.set('}', '{');

    let arr = []
    for (let i = 0; i < s.length; i++) {
        let l = map.get(s[i]);
            //右括号，拿出与栈顶匹配
        if (l) {
            let r = arr.pop();
            if (l !== r) return false
        }else{
            //否则，压如栈中
            arr.push(s[i])
        }
    }
    // 栈为空，则有效
    return arr.length === 0
};


```
