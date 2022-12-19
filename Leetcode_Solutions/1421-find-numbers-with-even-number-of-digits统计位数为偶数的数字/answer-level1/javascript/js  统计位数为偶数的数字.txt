需要注意的是计算数字的长度不能直接使用.length ，需要转为字符串才可以

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    let count = 0
    for (let i of nums) {
        let len = i.toString().length
        if (len%2 === 0) {
            count++
        }
    }
    return count
};
```
