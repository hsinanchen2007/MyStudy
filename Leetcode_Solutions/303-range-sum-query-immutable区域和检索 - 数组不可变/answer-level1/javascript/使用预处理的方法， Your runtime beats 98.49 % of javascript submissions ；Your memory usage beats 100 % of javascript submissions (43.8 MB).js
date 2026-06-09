先对传入的数组从0位一直到N位每一位之前的和求出。当计算i 至 j的和时，只需要把 用 j前面(包含 j )的和 减去 i前面(不包含 i )的和即可。
```javascript []
/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
    this.sum = Array(nums.length + 1);
    this.sum[0] = 0;
    for(let i = 0;i < nums.length ; i++) {
      this.sum[i + 1] = this.sum[i] + nums[i];
    }
};

/** 
 * @param {number} i 
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
    return this.sum[j + 1] - this.sum[i];
};
```

