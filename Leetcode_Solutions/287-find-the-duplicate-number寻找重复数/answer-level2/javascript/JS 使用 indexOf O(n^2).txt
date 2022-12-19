JavaScript 有 indexOf ，处理起来比较简单，不过效率嘛就...，indexOf 里面有 for，复杂度应该是 O(n^2)

```reasonml
var findDuplicate = function(nums) {
    for(let i = 0;i < nums.length;i++){
      if(nums.indexOf(nums[i]) !== nums.lastIndexOf(nums[i])){
          return nums[i]
      } 
    } 
};
```
