```
var smallestDivisor = function(nums, threshold) {
  let left = 1;
  let right = 1000000;
  while(left < right) {
    let mid = Math.floor((left + right) / 2);
    if (nums.reduce((a, b) => a + Math.ceil(b/mid), 0) <= threshold) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
};
```
