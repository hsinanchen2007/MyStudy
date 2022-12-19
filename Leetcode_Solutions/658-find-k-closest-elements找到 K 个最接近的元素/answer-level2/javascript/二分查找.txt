```
/**
 * @param {number[]} arr
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findClosestElements = function(arr, k, x) {
    if(x <= arr[0]) return arr.slice(0, k)
    const n = arr.length
    if(x >= arr[n - 1]) return arr.slice(n - k)
    let low = 0
    let high = n
    while(low < high) {
        const mid = parseInt((low + high) / 2)
        if(x < arr[mid]) {
            high = mid
        } else low = mid + 1
    }
    const index = low
    // 较小的数优先， 所以这里-1而不是+1
    low = Math.max(0, index - k - 1)
    high = Math.min(n - 1, index + k + 1)
    const len = k - 1
    while((high - low) > len){
        //这里用<=不用<是因为大的数优先级靠后
        if((x - arr[low]) <= (arr[high] - x)) {
            high--
        } else if((x - arr[low]) > (arr[high] - x)) low++
    }
    return arr.slice(low, high + 1)
};
```
