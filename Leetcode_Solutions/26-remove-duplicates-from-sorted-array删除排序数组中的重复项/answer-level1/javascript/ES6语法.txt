Set 去重，然后再赋值给原数组

```
var removeDuplicates = function(nums) {
    let newNums = [...new Set(nums)]
    newNums.map((v, k) => {
      nums[k] = v
    })
    return newNums.length;
};
```
