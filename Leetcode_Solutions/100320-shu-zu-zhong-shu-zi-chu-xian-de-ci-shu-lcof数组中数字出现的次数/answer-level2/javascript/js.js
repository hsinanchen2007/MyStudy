### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumbers = function (nums) {
    // 位运算，
    // 首先全部异或一遍，
    // 找到异或结果的随便一位为1；然后分成两个集合。分别异或
    let sum = nums.reduce((cur, pre) => {
        return cur ^= pre;
    }, 0)
    let k = 0;
    while (!(sum >> k & 1)) k++;
    let first = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] >> k & 1) first ^= nums[i];
    }
    return [first, sum ^ first];
};
```