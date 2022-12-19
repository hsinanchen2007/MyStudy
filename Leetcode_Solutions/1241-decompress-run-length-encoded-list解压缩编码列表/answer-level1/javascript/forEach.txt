### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function (nums) {
    let arr = []
    nums.forEach((item, index) => {
        if (index % 2 !== 0) {
            arr.push(...new Array(nums[index -1]).fill(item))
        }
    })
    return arr
};
```