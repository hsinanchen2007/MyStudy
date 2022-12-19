### 一遍哈希表

```js
const twoSum = function (nums, target) {
  if (Object.prototype.toString.call(nums) !== '[object Array]' || typeof target !== 'number') {
    alert("input type incorrect");
    return;
  }

  const arrMap = new Map()
  for (let i = 0; i < nums.length; i++) {
      const result = target - nums[i];
      if (arrMap.has(result)) {
        return [arrMap.get(result)+1, i+1]
      }
      arrMap.set(nums[i], i)
  }
};
```
> 124 ms	34.8 MB


### 双指针
```js
const twoSum = function (nums, target) {
  if (Object.prototype.toString.call(nums) !== '[object Array]' || typeof target !== 'number') return;

  let low = 0;
      high = nums.length - 1;
  while (low < high) {
    let sum = nums[low] + nums[high];
    if (sum < target) {
      low ++
    } else if (sum > target) {
      high --
    } else {
      return [low+1, high+1]
    }
  }
};
```
> 84 ms	35.4 MB
