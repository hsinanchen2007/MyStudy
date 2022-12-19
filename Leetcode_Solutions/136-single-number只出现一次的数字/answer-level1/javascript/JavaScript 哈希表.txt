```
/**
 * @param {number[]} nums
 * @return {number}
 * 哈希表 如果之前已经加进去了就吧这个key删掉，最后剩下来的那个唯一的key就是结果
 */
var singleNumber = function(nums) {
    let isExist = {};
    for (let i = 0; i < nums.length; i++) {
        if (!isExist[nums[i]]) {
            isExist[nums[i]] = true;
        } else {
            delete isExist[nums[i]];
        }
    }
    return Object.keys(isExist)[0];
};
```