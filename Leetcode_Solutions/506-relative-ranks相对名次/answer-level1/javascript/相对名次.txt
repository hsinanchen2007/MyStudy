```js
var findRelativeRanks2 = function(nums) {
    let nums2 = [...nums];
    nums2.sort((a, b) => b - a);
    let arr = [];
    let gold = nums.indexOf(nums2[0]);
    let silver = nums.indexOf(nums2[1]);
    let bronze = nums.indexOf(nums2[2]);
    for (let i = 0; i < nums.length; i++) {
        arr.push(nums2.indexOf(nums[i]) + 1 + '')
    }
    arr[gold] = 'Gold Medal';
    arr[silver] = 'Silver Medal';
    arr[bronze] = 'Bronze Medal';
    return arr
};
```
