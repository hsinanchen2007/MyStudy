```
/**
 * @param {number[]} arr
 * @return {number[][]}
 */

var minimumAbsDifference = function(arr) {
    let result = []
    let diff = null

    arr.sort((a, b) => a - b).reduce((prev, cur) => {
        let curDiff = cur - prev

        if (diff !== null && curDiff == diff) {
            result.push([prev, cur])
        } else if (diff === null || diff !== null && curDiff < diff) {
            diff = curDiff
            result = [[prev, cur]]
        }

        return cur
    })

    return result
};
```
