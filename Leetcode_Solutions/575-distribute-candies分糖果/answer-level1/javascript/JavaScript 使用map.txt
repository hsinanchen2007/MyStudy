### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} candies
 * @return {number}
 */
var distributeCandies = function(candies) {
    const len = candies.length
    if (!len) {
        return 0
    }
    const map = new Map()
    candies.forEach((item) => {
        map.set(item, map.has(item) ? map.get(item) + 1 : 1)
    })
    const count = map.size
    if (count >= (len / 2)) {
        return len / 2
    }
    return count
};
```