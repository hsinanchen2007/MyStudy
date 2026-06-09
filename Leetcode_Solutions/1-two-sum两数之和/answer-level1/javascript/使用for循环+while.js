### 解题思路
使用for循环+while来遍历数组，符合条件的直接return。优点是简单粗暴，缺点是没有性能可言。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  let res = [];
  for(let i=0;i<nums.length;i++){
	  res[0] = i;    
    let j = i+1;
    let num = target-nums[i];   
    while(j<nums.length){
      if(nums[j] === num){
        res[1] = j;
        return res;
      }
      j++;
    }
  }
  return res;
};
```