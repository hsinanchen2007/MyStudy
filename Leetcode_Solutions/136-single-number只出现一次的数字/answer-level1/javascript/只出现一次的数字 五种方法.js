## 第一版，暴力法
> 896ms,35.1M。
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  for (let i = 0; i < nums.length; i++) {
    if (nums.lastIndexOf(nums[i]) === nums.indexOf(nums[i])) return nums[i];
  }
};
```

## 第二版，哈希
> 116ms,37.5M。
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  let numsObj = {};
  for (let i = 0; i < nums.length; i++) {
    if (numsObj[nums[i]]) delete numsObj[nums[i]];
    else numsObj[nums[i]] = 1;
  }
  return Object.keys(numsObj)[0];
};
```

## 第三版，分割字符串
> 8860ms,41.7M。将数组转换成字符串，然后遍历使用每一项的值去分割字符串，若分割后数组长度为2则该项只出现一次。内存占用和耗时都较大，但还算容易理解。需要注意的是转为字符串后某一项可能包含另一项，例如"21"包含"2"，如果此时2为只出现一次的项则分割结果不准确，需要在字符串中加入分隔符区分每一项
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  const numsStr = `/${nums.join('//')}/`;
  for (let i = 0; i < nums.length; i++) {
    if (numsStr.split(`/${nums[i]}/`).length === 2) return nums[i];
  }
};
```

## 第四版，先排序再暴力
> 120ms,37.3M。比直接暴力的时间复杂度低很多，排序后只要某一项与它的前一项不同且与它的后一项也不同那它就是唯一项
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  nums = nums.sort();
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== nums[i - 1] && nums[i] !== nums[i + 1]) return nums[i];
  }
};
```

## 第五版，位运算 异或
> 80ms,35.2M。这个真没想到，看了题解之后写的，原理是将数组中所有数都一起异或之后值相同的项异或为0,0异或那个只出现一次的项结果为那个项本身
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  let temp = 0;
  for (let i = 0; i < nums.length; i++)
    temp ^= nums[i];
  return temp;
};
```