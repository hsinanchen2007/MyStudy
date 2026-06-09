耗时比较多……只提供一个思路
```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let temp = []
    function getNum(arr, i) {
        let left = 0
        let right = arr.length-1
        let mid = (left + right)>>1
        if(arr[left]==target) temp.push(left+i)
        if(arr[right]== target) temp.push(right+i)
        if(arr.length<=2) return
        if(arr[mid]>target){
            getNum(arr.slice(0, mid), i)
        } else if (arr[mid]<target){
            getNum(arr.slice(mid), i+mid)
        } else {
            getNum(arr.slice(0, mid), i)
            getNum(arr.slice(mid), i+mid)
        }
    }
    getNum(nums, 0)
    temp.sort(function(a,b){ return b-a})
    temp = Array.from(new Set(temp))
    if(temp.length == 0) return [-1, -1]
    if(temp.length == 1) return [temp[0], temp[0]]
    if(temp.length >= 2) return [temp[temp.length-1], [temp[0]]]
};
```
