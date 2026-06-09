```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    let hash = {}
    const result = []
    nums1.forEach((num, index) => {
        if (hash[num]) {
            hash[num]++
        }  else {
            hash[num] = 1
        }
    });
    
    nums2.forEach((num, index) => {
        if (hash[num]) {
            result.push(num)
            hash[num]--
        }
    })
    return result
    
```