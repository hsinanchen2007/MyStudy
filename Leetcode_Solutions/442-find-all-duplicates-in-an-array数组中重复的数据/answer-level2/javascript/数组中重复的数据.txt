//先将数组排序，然后顺序扫描数组。直到发现有重复数字；
```
var findDuplicates = function(nums) {
  const len = nums.length-1;
  const temp = [];
  if (nums.length <= 1) {
    return temp;
  }
  const sort = nums.sort((a, b) => {
    return a - b;
  });
  let index = 1;
  for (let i = 0; i <= len; i++) {
    if (nums[i] == nums[index]) {
      temp.push(nums[i]);
    }
    index++;
  }
  return temp;
};
```

//用一个set，顺序扫描数组，如果set没有包含当前数字，就把这个数字放入set,否则，就为重复数字。
```
var findDuplicates = function(nums) {
  const len = nums.length - 1;
  const set = new Set();
  const temp = [];
  if (nums.length <= 1) {
    return [];
  }
  for (let i = 0; i <= len; i++) {
    if (!set.has(nums[i])) {
      set.add(nums[i]);
    } else {
      temp.push(nums[i]);
    }
  }
  return temp;
};
```
