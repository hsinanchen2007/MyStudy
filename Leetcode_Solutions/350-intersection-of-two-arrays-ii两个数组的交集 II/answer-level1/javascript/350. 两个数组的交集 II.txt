```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    nums1 = nums1.sort((a,b)=> a-b)
    nums2 = nums2.sort((a,b)=> a-b)
    var numbers = []
    if(nums2.length > nums1.length){
        nums2.forEach(item => {
            if(nums1.indexOf(item) !== -1){
                numbers.push(item)
                nums1.splice(nums1.indexOf(item),1)
            }
        })
    }else{
        nums1.forEach(item => {
            if(nums2.indexOf(item) !== -1){
                numbers.push(item)
                nums2.splice(nums2.indexOf(item),1)
            }
        })
    }
    return numbers;
};
```
