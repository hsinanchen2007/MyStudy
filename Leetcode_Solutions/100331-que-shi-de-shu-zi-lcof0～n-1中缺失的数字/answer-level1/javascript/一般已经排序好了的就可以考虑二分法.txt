### 解题思路
一般已经排序好了的就可以考虑二分法，复杂度O(logn)
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
   // nums.sort((a,b)=>(a-b))
  // let dp=[];
    if(nums[0]!==0)return 0;
    if(nums[nums.length-1]===nums.length-1)return nums.length;
    let left=0;
    let right=nums.length-1;
    let mid;
    while(left < right-1){
        mid=Math.floor((left+right)/2);
        if(nums[mid]===mid){
            left=mid;
        }else{
            right=mid;
        }
    }
    return right;
   // return nums.length;

};
```