```
var sequentialDigits = function(low, high) {
  let nums = [1, 2, 3, 4, 5, 6, 7, 8];
  let tempNums = []; 
  let res = [];
  for (let i = 2; i <= 9; ++i) {
    for (let start = i, index = 0; start <= 9; ++start, ++index) {
      tempNums[index] = nums[index] * 10 + start;
      if (tempNums[index] < low) {
        continue;
      } else if (tempNums[index] <= high) {
        res.push(tempNums[index]);
      } else {
        i = 10;
        break;
      }
    }
    nums = tempNums;
  } 
  return res; 
};
```
