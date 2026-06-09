*法一*

```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var dominantIndex = function(nums) {
    if (nums.length == 1) {
        return 0
    }
    var nums2 = [...nums];
    nums.sort((a, b) => b -a);
    if(nums[0] >= 2*nums[1]) {
        return nums2.indexOf(nums[0])
    } else {
        return -1
    }
    
};
var nums = [3, 6, 1, 0];
console.log(dominantIndex(nums));
```

*法二*

```js
var dominantIndex = function(nums) {
    if (nums.length == 0) {
        return -1;
    }    
    if (nums.length==1) {
        return 0;
    }  
    let max = 0;
    let index = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > max){
            max = nums[i];
            index = i;
        }
    }
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] != max && nums[i]*2 > max)
            return -1;
    }
    return index;
}
```

