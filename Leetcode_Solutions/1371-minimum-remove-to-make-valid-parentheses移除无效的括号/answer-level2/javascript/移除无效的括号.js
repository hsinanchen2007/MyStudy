```
/**
 * @param {string} s
 * @return {string}
 */
var minRemoveToMakeValid = function(s) {
    let stack = [], //  字符串
        pos = [],   //  删除位置的索引
        left = 0;   //  "(" 出现的次数
    
    for (let i = 0; i < s.length; i++) {
        // 首先记录 "(" 出现的次数，假设所有 "(" 没有与之匹配的 ")" ,将其索引保存以便删除
        if (s[i] === "(") {
            left++;
            pos.push(i);
            stack.push(s[i]);
        } else if (s[i] === ")") {
            stack.push(s[i]);
            //  出现成对的括号，left--，删除对应 "(" 的索引
            if (left > 0) {
                left--;
                pos.pop();
            } else {
                // 没有与之对应的 "(", 将其索引保存以便删除
                pos.push(i);
            }
        } else {
            stack.push(s[i]);
        }
    }

    //  删除括号
    for (let i = 0; i < pos.length; i++) {
        stack[pos[i]] = "";
    }

    return stack.join("");
};
```
