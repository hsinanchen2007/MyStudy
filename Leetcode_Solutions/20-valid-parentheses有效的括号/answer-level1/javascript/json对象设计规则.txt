用对象设计一个规则:
 let pre=
        {
            '(':')',
            '[':']',
            '{':'}'
        };
，一次性遍历的时候使用规则，直接用key-value获得相应的值，然后判断pre[stack[stack.length-1]]===s[i]；
var isValid = function(s) {
    let stack=[];
    let res=1;
    let pre=
        {
            '(':')',
            '[':']',
            '{':'}'
        };
    for (let i = 0; i < s.length ; i++) {
        if (Reflect.has(pre,s[i]))
        {
            stack.push(s[i]);
        }
        else {
            if (pre[stack[stack.length-1]]===s[i])
            {
                stack.pop();
            }
            else
            {
                res=0
            }
        }

    }
    if (stack.length)res=0;
    return res;
};
PS：之前某个公司的初试就有这道题目；