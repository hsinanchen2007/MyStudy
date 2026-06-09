### 解题思路
最主要的就是找动态转移方程
当前的最大值，当前值和n-2值相加  比较  n-1的值，去一个最大值

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if(nums == null || nums.length ==0){return 0}
    // if(nums.length == 1){return nums[0]}
    // if(nums.length ==2){return Math.max(nums[0], nums[1])}
   let a = []
   a[1] = nums[0]
   a[0] = 0
   for(let i =2; i<= nums.length; i++){
       a[i] = Math.max(a[i-1] , a[i-2] + nums[i -1])
   }
   return a[nums.length]

};
```