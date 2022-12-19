### 解题思路
除了第一个数比较特殊外，其它出现非递减序列时，只有两种情况，要么改变前一个数为当前数，要么改变当前数为前一个数

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var checkPossibility = function(nums) {
    var len = nums.length;
    if (len === 1) return true;
    var count = 1;
    // 前两个数为非递减序列时，只需要将第一个数置为第二个数即可
    if (nums[1] < nums[0]) {
        count = 0
    };
    for (var i = 2; i < len; i++) {
        if (nums[i] < nums[i - 1]) {
            // 已经用光了机会，又来，只能返回false
            if (!count) return false
            // 只要发现非递减序列，count就应该减一
            count--;
            // 将前一个数置为当前数，然后看前面序列是否依然有序
            // 破坏了前序列的有序，说明修改前一个数为当前数行不通，因此只能修改当前数为前一个数来保证有序
            if (nums[i] < nums[i - 2]) { 
                nums[i] = nums[i - 1];
            }
        }
    }
    return true;
};
```