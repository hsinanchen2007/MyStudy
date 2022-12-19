```
/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 */
var backspaceCompare = function(S, T) {
    var sStack = []
    var tStack = []
    for (var i = 0; i < S.length; i++) {
        if (S[i] === '#') {
            sStack.pop()
        } else {
            sStack.push(S[i])
        }
    }
    for (var j = 0; j < T.length; j++) {
        if (T[j] === '#') {
            tStack.pop()
        } else {
            tStack.push(T[j])
        }
    }
    return sStack.join('') === tStack.join('')
};
```
