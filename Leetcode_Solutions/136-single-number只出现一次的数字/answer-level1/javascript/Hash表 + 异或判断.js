#### Hash表
直接在hash表中暴力分别记录每个值的出现次数，然后再遍历一次hash表，返回出现次数为1的元素
```javascript
var singleNumber = function (nums) {
    let map = new Map()
    for (let i = 0; i < nums.length; i++) {
        if (map.get(nums[i]) === undefined) {
            map.set(nums[i], 1)
        } else {
            map.set(nums[i], 2)
        }
    }
    const keysAry = Array.from(map.keys());
    for (let i = 0; i < keysAry.length; i++) {
        if (map.get(keysAry[i]) === 1) {
            return keysAry[i]
        }
    }
    return -1
};
```

#### 异或
依据：`a ^ a = 0`，因为只有目标值是单独出现的，所以将数组值依次累计异或，求得的值便是需要的答案
```javascript
var singleNumber = function (nums) {
    return nums.reduce((pValue, cValue) => pValue ^ cValue)
};
```