```
/**
 * @param {string} S
 * @param {string} T
 * @return {boolean}
 */
var backspaceCompare = function(S, T) {
    let f = (str) => {
        let result = []
        let arr = str.split('')
        for (let i = 0; i < arr.length; i++) {
            if (arr[i] === '#') {
                result.pop()
            } else {
                result.push(arr[i])
            }
        }
        return result.join('')
    }
    return f(S) === f(T)
};
```