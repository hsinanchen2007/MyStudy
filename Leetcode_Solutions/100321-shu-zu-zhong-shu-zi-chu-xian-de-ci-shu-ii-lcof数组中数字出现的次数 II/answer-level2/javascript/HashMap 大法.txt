### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {

    let freq = new Map() // freq == frequence
    for (const c of nums) {
        if (freq.has(c)) freq.set(c, freq.get(c) + 1)
        else freq.set(c, 1)
    }

    // console.log(Array.from(freq).sort((a, b) => a[1] - b[1]))
    return Array.from(freq)
            .sort((a, b) => a[1] - b[1])[0][0]  // sort by frequency
};
```