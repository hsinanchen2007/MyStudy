``` javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var wiggleSort = function(nums) {
  let nums2 = nums.sort((a, b) => b - a).splice(nums.length % 2 == 0 ? nums.length / 2 : (nums.length -1) / 2),
      pushIndex = 0,
      forNUmber = nums2.length;
  
  for(let i = 0; i < forNUmber; i++) {
    nums.splice(pushIndex, 0, nums2[i]);
    pushIndex += 2;
  }
  return nums
};
```

方法不是很好，但能解。
