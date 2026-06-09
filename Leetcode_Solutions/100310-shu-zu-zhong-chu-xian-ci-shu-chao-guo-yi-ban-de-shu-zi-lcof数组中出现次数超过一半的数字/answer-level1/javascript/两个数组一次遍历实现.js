### 解题思路
一个数组储存无重复个体，另一个数组对无重复个体数组中的数进行计数

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    var eachdiff = []
    var numsn = []
    var len = nums.length
    for (let item of nums) {

        if (eachdiff.indexOf(item) < 0) {
            eachdiff.push(item)
            numsn.push(1)
        } else {
            numsn[eachdiff.indexOf(item)]++
        }
        if (numsn[eachdiff.indexOf(item)] >= len / 2) {
            return item
        }
    }

};

```