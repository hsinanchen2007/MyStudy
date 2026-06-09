```
/**
 * @param {string} S
 * @return {string}
 */
var removeOuterParentheses = function(S) {
    var stack = []
    var count = 0
    for (var i = 0; i < S.length; i++) {
        if (S[i] === '(') {
            count ++
            // 根据数量判断
            if (count >= 2) {
                stack.push(S[i])
            }
        } else if (S[i] === ')') {
            count --
            // 根据数量判断
            if (count >= 1) {
                stack.push(S[i])
            }
        }
    }
    return stack.join('')
};
```
