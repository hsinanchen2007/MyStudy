# 代码
## 第一版，一次splice当前项的一个重复值
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    for (let i = 0; i < nums.length;) {
      if (nums[i] === nums [i + 1]) nums.splice(i, 1);
      else i ++;
    }
  return nums.length;
};
```
## 第二版，一次splice当前项的所用重复值，需要对当前项有多少个重复值计数，耗时比第一版增加了不少
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
  let index = 0;
  let num = 0;
  for (let i = 0; i < nums.length + 1; i++) {
    if (nums[i] === nums[i + 1]) num++;
    else {
      nums.splice(index, num);
      num = 0;
      i = index++;
    }
  }
  return nums.length;
};
```
## 第三版，仔细思索了一下题目发现其实可以并不用删除数组项，只要把数组中的n个非重复项按顺序赋值替代数组的前n项即可。后面看了题解大概和双指针法是同样的思路吧
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
  let len = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== nums[i + 1]) {
      nums[len] = nums[i];
      len++;
    };
  }
  return len;
};
```
