### 解题思路
首先遍历数组，把数组中的元素当做map中的key，value为出现的次数，出现一次增加1
便利map中所有的value存到一个数组中，实际上现在只要知道数组中有没有重复元素就知道是否是独一无二。
判断数组是否有重复元素不用去重，利用object的键唯一的特性即可。

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
    var res = []; //存储所有数字出现的次数，就是存储value即可
    var flag = true;
    var map = new Map();
    for (let i = 0; i < arr.length; i++) {
        //利用Map的数据结构统计次数
        if (!map.has(arr[i])) {
            map.set(arr[i], 1)
        } else {
            map.set(arr[i], map.get(arr[i]) + 1)
        }
    }
    for (let value of map.values()) {
        res.push(value)
    }
    //现在只需要判断res这个数组是否有重复值即可知道是否独一无二
    let obj = {};
    for (let j = 0, length = res.length; j < length; j++) {
        obj[res[j]] = j;
    }
    if (res.length !== Object.keys(obj).length) {
        flag = false
    }
    return flag;
};
```