```
/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    let res = []
    let tmp = path.split('/')
    tmp = tmp.filter(item => item != '')
    tmp.forEach((item, index) => {
        if (item === '.') {
        } else if (item === '..') {
            res.splice(res.length - 1, 1)
        } else {
            res.push(item)
        }
    })
    return '/' + res.join('/')
};
```
