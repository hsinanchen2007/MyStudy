```
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function (target) {
    let tar = target, max = Math.round(target / 2)
    let ans = [], arr = [], i = j = 1
    while (i <= max) {
        tar = tar - i
        arr.push(i)
        if (tar === 0) {
            ans.push(arr)
            j++
            i = j
            arr = []
            tar = target
        } else if (tar < 0) {
            j++
            i = j
            arr = []
            tar = target
        } else {
            i++
        }
    }
    return ans
};
```
