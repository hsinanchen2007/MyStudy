## 第一版，暴力法
> 65ms,33.9M,击败99.75%。耗时在意料之外
```javascript []
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
  const intersection = [];
  for(let i = 0; i < nums1.length; i++) {
    let j = nums2.indexOf(nums1[i]);
    if(j > -1) {
      intersection.push(nums2.splice(j,1)[0]);
    }
  }
  return intersection;
};
```
## 第二版，hash
> 104ms,36.3M。使用两个对象分别存储两个数组所有元素以及各元素出现的次数，然后再遍历两个对象中都存在的key，取值更小的那个value作为该key出现的次数。往交集数组中添加对应value值次数的key值
```javascript []
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
  const intersection = [];
  const nums1Obj = {};
  const nums2Obj = {};
  
  for(let i = 0; i < nums1.length; i++) {
    if (nums1Obj[nums1[i]]) nums1Obj[nums1[i]]++;
    else nums1Obj[nums1[i]] = 1;
  }
  
  for(let i = 0; i < nums2.length; i++) {
    if (nums2Obj[nums2[i]]) nums2Obj[nums2[i]]++;
    else nums2Obj[nums2[i]] = 1;
  }
  
  const keys = Object.keys(nums1Obj);
  for (let i = 0; i < keys.length; i++) {
    if (nums2Obj[keys[i]]) {
      let j = nums2Obj[keys[i]] > nums1Obj[keys[i]] ? nums1Obj[keys[i]] : nums2Obj[keys[i]];
      intersection.splice(0,0, ...new Array(j).fill(+keys[i]));
    }
  }
  return intersection;
};
```

## 第三版，hash，对第二版的优化
> 92ms,35.2M。想了一下发现第二个对象没有必要完全构造出来，可以边查询比较边往交集数组中插入
```javascript []
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
  const intersection = [];
  const numsObj = {};
  
  for(let i = 0; i < nums1.length; i++) {
    if (numsObj[nums1[i]]) numsObj[nums1[i]]++;
    else numsObj[nums1[i]] = 1;
  }
  
  for(let i = 0; i < nums2.length; i++) {
    if (numsObj[nums2[i]]) { 
      numsObj[nums2[i]]--;
      intersection.push(nums2[i]);
    }
  }
  
  return intersection;
};
```
## 第四版，先排序再暴力
> 108ms,35M。这个方法的主要耗时在排序部分。
```javascript []
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
  nums1 = nums1.sort((a, b) => a - b);
  nums2 = nums2.sort((a, b) => a - b);
  const intersection = [];
  for(let i = 0, j = 0;i < nums1.length && j < nums2.length;) {
    if (nums1[i] > nums2[j]) {
      j++;
    } else if (nums1[i] < nums2[j]) {
      i++;
    } else {
      intersection.push(nums1[i]);
      i++;
      j++;
    }
  }
  return intersection;
};
```