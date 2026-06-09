### 解题思路
先求前缀和，然后滑动窗口

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    let left = 0
    let max = Math.ceil(target / 2)
    let right = 1
    let arr = [0]
    let items = []
    let res = []
    for(let i = 1; i <= max; i++) {
        arr.push(arr[i - 1] + i)
        items.push(i)
    }
    while (right > left && right <= max) {
        // console.log(right, left, arr[right] - arr[left])
        if(arr[right] - arr[left] === target){
            res.push(getItem(left, right))
            right++
        } else if (arr[right] - arr[left] > target) {
            left++
        } else {
            right++
        }
    }
    function getItem(left, right) {
        let item = items.splice(left ,right - left )
        items.splice(left ,0, ...item)
        return item
    }
    return res
};
```