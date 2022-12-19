```
/**
 * @param {string} s
 * @return {string}
 */
var decodeString = function(s) {
    let stack = [];
    let ans = ''
    let multi = 0
    for (let o of s) {
        if (!isNaN(Number(o))) {
            multi = multi*10 + Number(o)
        } else if (o === '[') {
            stack.push([ans, multi])
            ans = ''
            multi = 0
        } else if (o === ']') {
            [last_str, num] = stack.pop();
            let temp_str = ''
            for (var i = 0; i < num; i ++) {
                temp_str += ans
            }
            ans = last_str + temp_str 
        } else {
            ans += o
        }
    }
    return ans
};
```