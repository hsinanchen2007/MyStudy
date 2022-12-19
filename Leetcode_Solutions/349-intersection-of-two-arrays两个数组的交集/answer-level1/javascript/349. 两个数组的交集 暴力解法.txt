```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    var nums3 = []
    for(var i = 0;i < nums1.length; i++){
        if(nums2.indexOf(nums1[i])!== -1){
            if(nums3.indexOf(nums1[i]) === -1){
                nums3.push(nums1[i])
            }            
        }
    }
    return nums3;
};
```
