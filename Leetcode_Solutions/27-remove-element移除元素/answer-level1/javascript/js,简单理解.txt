
通过while循环，因为splice会改变原数组，当两个符合条件的数挨在一起的时候，使用if来判断就会导致有一个删不掉，那么使用while循环就不会出现这样的问题，当两个相同的符合条件的数在一起的时候，先会删除一个，然后nums[i]指向的就是下一个符合条件的数，会继续删除。

```
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    for (let i=0;i<nums.length;i++){
        while(nums[i]==val){
           nums.splice(i,1)
        }
        
    }
    
    return nums.length
};
```
