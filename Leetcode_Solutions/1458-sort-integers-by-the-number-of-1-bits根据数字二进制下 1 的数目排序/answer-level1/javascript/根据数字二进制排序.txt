### 解题思路
1. 对数组升序排序
2. 获得数字的二进制数中1的个数，并放在hash表里
3. 升序变量hash表，输出

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number[]}
 */
var sortByBits = function(arr) {
    arr = arr.sort((a,b)=> a - b)
    console.log(arr)
    const hash = {}
    arr.forEach(num => {
        let numberOneLength = num.toString(2).split("0").join("").length
        if(hash[numberOneLength]) {
            hash[numberOneLength].push(num)
        } else {
            hash[numberOneLength] = [num]
        }
    })
    const r = []
    console.log(hash)
    Object.keys(hash).forEach(key => {
        console.log(key)
        r.push(...hash[key])
    })
    return r
};
```