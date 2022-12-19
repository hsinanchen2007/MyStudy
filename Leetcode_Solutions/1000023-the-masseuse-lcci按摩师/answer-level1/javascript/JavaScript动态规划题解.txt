### 解题思路
当前第n个数的最优解`f(n)`，一定是第n-2个数的最优解加当前数`f(n-2)+nums[n]`，和第n-1个数的最优解`f(n-1)`中较大的那个。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    if(nums.length===0)return 0;
    let pre = 0;
    let now = nums[0];
    for(let i=1;i<nums.length;i++){
        let tmp = now;
        now = Math.max(pre + nums[i],now);
        pre = tmp;
    }
    return now;
};
```