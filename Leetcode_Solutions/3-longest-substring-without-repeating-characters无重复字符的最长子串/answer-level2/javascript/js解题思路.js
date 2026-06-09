### 解题思路


### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let strArr = []
    let tmpArr = []
    let maxLen = -1
    if (typeof s !== 'string') {
        return false
    }
    strArr = s.split('')
    strArr.forEach(item =>{
        if (tmpArr.indexOf(item) !== -1) {
            maxLen = maxLen > tmpArr.length ? maxLen : tmpArr.length // 当前子串中有该项时，记录当前子串长度
            tmpArr.splice(0, tmpArr.indexOf(item) + 1) // 删除临时数组中该项之前的字段
            if (item === tmpArr[tmpArr.length-1]) {
                // 如果数组只剩最后一项，且跟当前项相等，说明两个连续重复的数字，数组清空
                tmpArr = []
            }
        }
        // 把新项放到数组最后一项
        tmpArr.push(item)
    })
    maxLen = maxLen > tmpArr.length ? maxLen : tmpArr.length
    if (maxLen === -1) {
        maxLen = tmpArr.length
    }
    return maxLen
};
```