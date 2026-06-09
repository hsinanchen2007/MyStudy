### 解题思路
此处撰写解题思路
循环得到每项出现的次数，放在一个对象中然后 循环对象key得到出现最大次数的项
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
const majorityElement = function(nums) {
  const map = {};
  let ele;
  let max = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] in map) {
      map[nums[i]] = map[nums[i]] + 1;
      continue;
    }
    map[nums[i]] = 1;
  }
  for (const key in map) {
    if (map[key] > max) {
      max = map[key];
      ele = key;
    }
  }
  return ele;
};
```