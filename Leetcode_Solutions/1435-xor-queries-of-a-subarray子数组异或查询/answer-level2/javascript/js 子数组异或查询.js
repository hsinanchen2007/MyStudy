![image.png](https://pic.leetcode-cn.com/c954c1d0ea288d189b81cfe20de5d78010b714fb4ae32b3c3c78bd3b590c4023-image.png)

思路：提高效率需存储重复的异或结果避免重复运算；
因为两个相同数字异或等于0，0与任何数异或等于数字本身，因此[a,b]区间的数字异或等于[0,b]区间异或结果与[0, a-1]区间异或结果的异或；
用 map 存储 arr 0-n位的异或值；

```
/**
 * @param {number[]} arr
 * @param {number[][]} queries
 * @return {number[]}
 */
var xorQueries = function(arr, queries) {
    let xorArr = []
    const arrLen = arr.length
    let map = new Map()
    map.set(0, arr[0])
    for(let i = 1; i < arrLen; i++) {
        let value = map.get(i-1)
        map.set(i, value^arr[i])
    }
    for(let i of queries) {
        let value1 = map.get(i[0]-1)
        let value2 = map.get(i[1])
        let num = value2 ^ value1
        xorArr.push(num)
    }
    return xorArr
};
```
