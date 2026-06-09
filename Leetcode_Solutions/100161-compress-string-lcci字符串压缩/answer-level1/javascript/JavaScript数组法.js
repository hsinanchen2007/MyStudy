### 解题思路

通过数组存储再拉平得出结果

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    const arr = S.split(''), temp = []
    for (let i = 0; i < arr.length; i++) {
        let a = i // 存下当前下标
        temp[a] = [arr[i], 1]
        while (arr[i] === arr[i + 1]) {
            temp[a][1]++
            i++
        }
    }
    const str = temp.join('').split(',').join('') // 不支持flat只能这样拉平
    return str.length >= S.length ? S : str
};
```