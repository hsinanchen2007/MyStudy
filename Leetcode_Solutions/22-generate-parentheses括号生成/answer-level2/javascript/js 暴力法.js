```
var generateParenthesis = function(n) {
    let combinations = [];
    (function combination(n,res,index) {
        let concatRes = [];
        if(res.length === 0)
            concatRes = ['('];
        else{
            res.map(item => {
                concatRes.push(item + '(');
                concatRes.push(item + ')');
            })
        }
        if(index === n)
            return combinations = concatRes;
        else{
            return combinations = combination(n, concatRes, ++index);
        }
    })(2 * n,[],1);
    let res = [];
    combinations.forEach(item => {
        if(isValid(item))
            res.push(item);
    })
    function isValid(s){
        let stack = [];
        for(let i = 0; i < s.length; i++){
            if(stack.length === 1 && stack[stack.length - 1] === ')')
                break;
            if(stack.length === 0)
                stack.push(s[i]);
            else{
                if(stack[stack.length - 1] === s[i]){
                    stack.push(s[i]);
                }else{
                    stack.pop();
                }
            }
        }
        if(stack.length === 0)
            return true;
        return false;
    }
    return res;
};
```