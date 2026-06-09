1. 通俗的寻找峰值的思路是遍历数组的每一个元素，并判断是否大于前后的值
2. 可在步骤1的基础上做个优化，无需比较当前值与前一个值
3. 例：[2, 3, 1]与[5, 3, 1]当前值均为3的话，[2,3,1]则通过判断3>1为峰；[5,3,1]5>3则为峰，峰值已返回，无需后续判断
```
/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums = []) {
    const length = nums.length;
    let index = length - 1;
    
    for(let i = 0; i < length - 1; i++) {
        const item = nums[i];
        const after = nums[i + 1];

        if(item > after) {
            return i;
        }
    }

    return index;
};
```
