### 解题思路
此处撰写解题思路

### 代码
遍历 O(n),执行用时48ms，内存消耗34.6MB
```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let i = 0
    while(i<nums.length) {
        if (nums[i]<target) {
            i++
            continue
        } else {
            return i
        }  
    }
    return i
};
```
二分法 第二版 Olog(n) 执行用时76ms，内存消耗34MB
```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let l = 0, r = nums.length
    while(l < r) {
        let mid = Math.floor((l+r)/2)
        if (nums[mid]>target) {
            r = mid
            continue
        } else if (nums[mid]<target) {
            l = mid + 1
            continue
        } else {
            return mid
        }
    }
    return r
};
```
第三版，参考他人写法，将思路优化 执行用时 68ms，内存消耗34.1MB
```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let len = nums.length
    if (nums[len-1]<target) return len
    let l = 0, r = len
    while(l < r) {
        let mid = (l+r)>>>1
        if (nums[mid]<target) {
            l = mid + 1
        } else {
            r = mid
        }
    }
    return r
};
```