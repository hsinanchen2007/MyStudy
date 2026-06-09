贴一个中规中矩的解法：
维护一个双维数组，如：[[t], [r], [e, e]]。然后按照内层数组的length进行排序，最后将这个二维数组拍扁。
因为leetcode内置好像不支持flat方法所以用的reduce进行合并操作。

```javascript []
var frequencySort = function(s) {
    let arr = []
    for(let char of s) {
        const index = arr.findIndex(item => item[0] === char)
        if(index > -1) {
            arr[index].push(char)
        } else {
            arr.push([char])
        }
    }
    const result = arr.sort((a, b) => b.length - a.length)
    return result.reduce((acc, cur) => `${acc}${cur.join('')}`, '')
}
```

