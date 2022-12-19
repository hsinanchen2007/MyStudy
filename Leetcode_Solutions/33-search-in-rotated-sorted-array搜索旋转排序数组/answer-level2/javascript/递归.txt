```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let len = -1
    function index(arr, i) {
        if(arr.length <= 2) {
            arr[0] == target ? len = i : -1
            arr[1] == target ? len = i+1 : -1
            return
        }
        let left = 0
        let right = arr.length-1
        let center = Math.floor(arr.length/2)
        index(arr.slice(left, center), left+i)
        index(arr.slice(center), center+i)
    }
    index(nums, 0)
    return len
};
```
