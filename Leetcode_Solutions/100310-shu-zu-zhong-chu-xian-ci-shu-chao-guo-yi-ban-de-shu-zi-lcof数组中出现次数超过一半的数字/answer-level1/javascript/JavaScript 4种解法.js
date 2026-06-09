### 解题思路
1. JavaScript api Map
2. 自己定义一个hash map，记录每个元素出现的次数，返回那个超过数组长度一半的
3. 由于必定会有一个数字出现次数超过数组长度一半，可知排序后其一定在中位数
4. 投票法，先选定数组第一个元素为基点，如果遇到相同的元素则count+1，否则-1，减到0后则换数字。已知数组一定会有一个数字出现次数超过数组长度的一半，则这个元素最后的count必定大于等于1。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
  let hashMap = new Map();

  for(let i of nums) {
    if ( !hashMap.has(i) ) {
      hashMap.set(i, 1)
    } else {
      let iVal = hashMap.get(i) + 1;
      hashMap.set(i, iVal)
    }
  }

   for (let key of hashMap.keys()) {
        if (hashMap.get(key) >= Math.ceil(nums.length / 2)) {
          return key
        }
    }
};
```


```javascript

var majorityElement = function(nums) {
  let hashMap = {};

  for(let i of nums) {
    if ( !hashMap[i] ) {
      hashMap[i] = 1;
    } else {
      hashMap[i] = hashMap[i] + 1;
    }
  }

   for (let key in hashMap) {
        if (hashMap[key] >= Math.ceil(nums.length / 2)) {
          return key
        }
    }
};
```


```javascript

var majorityElement = function(nums) {
  nums = nums.sort((a, b) => a-b)
  return nums[Math.floor(nums.length/2)]
};
```


```javascript

var majorityElement = function(nums) {
  let count = 0;
  let majority = nums[0];

  for(let i in nums) {
    if(count == 0) {
      majority = nums[i] // 更换候选的数
    }

    if(nums[i] == majority) {
      count++;
    } else {
      count--;
    }
  }

  return majority;
};
```