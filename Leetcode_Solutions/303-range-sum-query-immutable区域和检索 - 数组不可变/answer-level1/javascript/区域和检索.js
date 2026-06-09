### 解题思路
把数组索引0-i的和 存到i-1索引的位置
这样数组nums第i个位置的值就是 0-i 的和
要求 i-j的和，只需要用 0-j的和 减去 0-（i-1）的和

### 代码

```javascript
/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
    //this.num = nums;
    for(i=1;i<nums.length;i++){
        nums[i] += nums[i-1];
    }
    this.nums = nums;
};

/** 
 * @param {number} i 
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
    if(i==0) return this.nums[j];
    return this.nums[j]-this.nums[i-1];
};

/**
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(i,j)
 */
```