### 解题思路
方法一、哈希表

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    var map = new Map();
    for(var i=0;i<nums.length;i++){
            map.set(nums[i],i);
    }
    for(i=0;i<nums.length+1;i++){
        if(map.has(i)==false){
            return i;
        }
    }
};
```
方法二、数学
前n个数之和减去数组之和
```
var missingNumber = function(nums) {
    var sum1 = (nums.length)*(nums.length+1)/2;
    var sum2=0;
    for(var i=0;i<nums.length;i++){
        sum2 += nums[i];
    }
    return sum1-sum2;
};
```
