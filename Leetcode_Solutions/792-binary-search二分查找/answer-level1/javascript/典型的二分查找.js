### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
  let l = 0;
  let r = nums.length;
  while(l<=r) {
    let mid = l+ ((r-l)>>>1); // 防止溢出
    if(nums[mid]===target){
      return mid
    }else if(nums[mid]<target){
      l = mid+1
    }else{
      r = mid-1
    }
  }
  return -1
};
```