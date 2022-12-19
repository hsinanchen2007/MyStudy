```
/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
function maxSumSubmatrix (matrix, K) {
    let max = -Infinity;
    const m = matrix.length;
    const n = matrix[0].length;

    for (let i = 0; i < n; i++) {
        const rowSum = Array(m).fill(0);

        for (let j = i; j < n; j++) {
            for (let k = 0; k < m; k++) {
                rowSum[k] += matrix[k][j];
            }

            let sum = 0;
            const arr = [0];

            for (let r = 0; r < m; r++) {
                sum += rowSum[r];

                // js中的Set没有ceiling或者lowerbound方法，
                // 所以实现一个方法查找应当插入值的位置
                let idx = insertIndex(arr, sum - K);

                idx = idx >= arr.length ? arr.length - 1 : idx;
                const val = sum - arr[idx];

                if (idx > -1 && val <= K) {
                    if (val === K) return K;
                    else max = Math.max(max, val);
                }

                const insertIdx = insertIndex(arr, sum);
                if (arr[insertIdx] !== sum) {
                    // 在合适的index位置插入该值，保证arr是个有序数组
                    arr.splice(insertIdx, 0, sum);
                }
            }

        }
    }

    return max;
}

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
function insertIndex(nums, target){
    let low = 0;
    let high = nums.length - 1;
    let mid;

    while (low <= high) {
        mid = (low + high) >> 1;

        if (nums[mid] === target) {
            return mid;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}
```
