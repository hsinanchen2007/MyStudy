*法一*

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let arr = nums.join('').split('0');
    let max = 0;
    arr.forEach((item) => {
        if(item.length > max) {
            max = item.length
        }
    })
    return max;
};
var nums = [1,1,0,1,1,1];
console.log(findMaxConsecutiveOnes(nums));
```

*法二：一遍遍历一遍比较*

```js
var findMaxConsecutiveOnes = function(nums) {
    let max = 0;
    let count = 0;
    for(let i = 0; i < nums.length; i++) {
        if (nums[i] == 1) {
            count++;
        } else {
            max = Math.max(max, count)
            count = 0;
        }
    }
    max = Math.max(max, count)
    return max
};
```

