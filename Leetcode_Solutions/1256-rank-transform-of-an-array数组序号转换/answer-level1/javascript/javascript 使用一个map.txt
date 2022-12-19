### 解题思路
使用一个map保存数组元素排序信息
![leetcode1331.jpg](https://pic.leetcode-cn.com/1007b9d527513bd0ccd92cd7bf2e55469c77d309e4e2e5cd77bf819f89f6fcb7-leetcode1331.jpg)


### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number[]}
 */
var arrayRankTransform = function(arr) {
    const len = arr.length
    if (len === 0) {
        return []
    }
    if (len === 1) {
        return [1]
    }
    const temp = [...arr]
    temp.sort((a, b) => a - b)
    const map = new Map()
    let index = 1
    for (let i = 0; i < len; i++) {
        if (!map.has(temp[i])) {
            map.set(temp[i], index++)
        }
    }
    const res = []
    for (let i = 0; i < len; i++) {
        if (map.has(arr[i])) {
            res.push(map.get(arr[i]))
        }
    }
    return res
};
```