### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function (nums) {
    let temp = 0;
    for (let i = 0; i < nums.length; i++) {
        // 二进制码 位异或 运算 相同抵消为0 不同写1
        console.log(temp, nums[i].toString(2))
        temp ^= nums[i];
        console.log(temp.toString(2))
    }

    return temp
};
```