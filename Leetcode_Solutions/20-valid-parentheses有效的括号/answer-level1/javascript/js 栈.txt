```
var isValid = function(s) {
    let stack = [];
    let compareJson = {
        1: 2,
        2: 1,
        3: 4,
        4: 3,
        5: 6,
        6: 5
    };
    for(let i = 0; i < s.length; i++){
        let correspond = -1;
        switch (s[i]){
            case '(':
                correspond = 1;
                break;
            case ')':
                correspond = 2;
                break;
            case '[':
                correspond = 3;
                break;
            case ']':
                correspond = 4;
                break;
            case '{':
                correspond = 5;
                break;
            case '}':
                correspond = 6;
                break;
        }
        if(stack.length === 0)
            stack.push(compareJson[correspond]);
        else{
            if(correspond === stack[stack.length - 1]){
                stack.pop();
            }else{
                stack.push(compareJson[correspond]);
            }
        }
    }
    if(stack.length > 0)
        return false;
    return true;
};
```