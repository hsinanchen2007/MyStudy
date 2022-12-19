结题思路：假设2+7=9，只遍历一次的情况下，2和7都会遍历到，我们在遍历2的时候检查一个map中是否包含7如果有那么存在，如果没有就添加到map中。主要的解题关键是会2和7都会遍历一次，2错过了添加到map等到了7在匹配成功。

var twoSum = function(nums, target) {
    const map = new Map();
    const len = nums.length;
    const res = [];
    for (let i = 0; i < len; i += 1) {
        const want = target - nums[i];
        const value = map.get(want);
        if (value) {
            res.push(value);
            res.push(i - 1);
        } else {
            map.set(nums[i], i + 1);
        }
    }
    return res;
};