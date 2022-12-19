```

var isValid = function(str) {
    if (!str.length)
        return true;
    if (str.length % 2 != 0)
        return false;
    let list = [str[0]];
    for (let i = 1; i < str.length; i++) {
        let l = list.length;
        let s = str[i];
        let flag = (list[l - 1] == '(' && s == ')') || (list[l - 1] == '[' && s == ']') || (list[l - 1] == '{' && s == '}');
        if (flag) {
            list.pop();
        } else
            list.push(str[i]);
    }
    return !list.length
};
```
