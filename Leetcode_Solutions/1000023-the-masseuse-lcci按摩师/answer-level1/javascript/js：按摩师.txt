### 解题思路
只能通过大佬的思路来进行coding，哭泣

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    //递归方程：arr[i] = Math.max(arr[i-1], arr[i-2]+nums[i]);
    let length = nums.length;
    if(length === 0){
        return 0;
    }
    if(length === 1){
        return nums[0];
    }
    let arr = [];
    arr[0] = nums[0];
    arr[1] = Math.max(nums[0], nums[1]);
    for(let i = 2; i < length; i ++){
        arr[i] = Math.max(arr[i-1], arr[i-2] + nums[i]);
    }
    return arr[length - 1];
};
```