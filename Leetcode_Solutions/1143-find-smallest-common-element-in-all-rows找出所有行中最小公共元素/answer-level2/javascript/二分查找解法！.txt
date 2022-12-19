### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} mat
 * @return {number}
 */
var smallestCommonElement = function(mat) {

    const M = mat.length, N = mat[0].length

    for (let j = 0; j < N; j++) { // column
        let flag = true
        for (let i = 1; i < M; i++) { // row
            if (!binarySearch(mat[i], mat[0][j])) {
                flag = false
                break
            }
        }

        if (flag) return mat[0][j]
    }

    return -1
};

/**
 * 二分查找
 */
const binarySearch = (arr, target) => {
    let l = 0, r = arr.length - 1
    while (l <= r) {
        let mid = (l + r) >> 1 // 用位运算装一下... 为了取代 mid = Math.trunc((l + r) / 2)
        if (target == arr[mid]) return 1
        if (target > arr[mid]) l = mid + 1
        else r = mid - 1
    }
    return 0
}
```