### 解题思路
先转换成字符串，使用原生的sort方法进行排序，每次对比时，比较 a + b 和 b + a 哪个数字更大即可。此方法有个问题在于，如果本身这个数字就很大时，无法用于数字比较，就不适用此方法。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    nums = nums.map(i => i + "")
    let res = nums.sort((a,b)=> {
        let x = +(a + b)
        let y = +(b + a)
        return x > y ? -1 : 1
    })
    res = res.join("")
    if(+res === 0) {
        res = "0"
    }
    return res
};
```