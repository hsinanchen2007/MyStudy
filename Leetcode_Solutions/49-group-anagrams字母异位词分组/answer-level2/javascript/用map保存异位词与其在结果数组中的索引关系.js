### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    let result = []
    let wordMap = new Map()
    let i = 0
    strs.forEach(ele => {
        let sortEle = ele.split('').sort().join('')
        if (wordMap.has(sortEle)) {
            result[wordMap.get(sortEle)].push(ele)
        } else {
            wordMap.set(sortEle, i++)
            result.push([ele])
        }
    })
    return result
};
```