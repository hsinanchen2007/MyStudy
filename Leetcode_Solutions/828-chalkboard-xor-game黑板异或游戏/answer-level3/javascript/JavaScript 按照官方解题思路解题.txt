### 解题思路
按照官方解题思路，就是说什么时候为true，就是XOR为0的时候或者是偶数的时候，因为偶数的时候小红将不会是擦除黑板的人

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var xorGame = function(nums) {
    let x = 0;
    for(let i=0; i<nums.length;i++){
       x ^=nums[i];
    }
    return nums.length%2 === 0 || x === 0;
};
```