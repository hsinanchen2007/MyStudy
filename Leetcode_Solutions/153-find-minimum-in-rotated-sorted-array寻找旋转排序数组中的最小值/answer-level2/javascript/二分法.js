### 解题思路
注意let mid Math.floor(l + (r -l)/2)
mid>=l  mid < r ，换算成式子也是一样的nums[mid] < nums[r]   nums[mid] >= nums[l]
然后注意左移右移的情况，是不是需要加1
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let l =0, r= nums.length -1
    while(l  < r){
        let mid  = Math.floor(l + (r -l)/2)
        if(nums[mid] > nums[r]){
            l = mid +1
        }else{
            r = mid
        }
    }
    return nums[r]
};
```